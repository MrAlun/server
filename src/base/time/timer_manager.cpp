#include "timer_manager.h"

#include "global.h"
#include "time/timer.h"
#include "thread/thread_pool.h"
#include "thread/thread_lock.h"
#include "thread/thread_func.h"

void TimerManagerFunc( void *param );

TimerManager::TimerManager()
	: m_start( false )
	, m_delay( 1 )
{
	Thread::API::MutexInit( &m_lock, NULL );
}

TimerManager::~TimerManager()
{
}

void TimerManager::AddTimer( Timer* timer )
{
	Thread::GuardLock lock( &m_lock );
	m_list.push_back( timer );
	timer->m_status = Timer::TIMER_STATUS_ALIVE;
}

void TimerManager::RemoveTimer( Timer* timer )
{
	for ( auto it = m_list.begin() ; it != m_list.end() ; ++it )
	{
		if ( timer == *it )
			m_list.erase( it++ );
		else
			++it;
	}
}

void TimerManager::Start( Thread::ThreadPool& pool )
{
	if ( pool.Running() )
		pool.Join( this );
	else
		g_log.Error( "The ThreadPool do not running!\n" );
}

void TimerManager::Stop()
{
	m_start = false;
}

void TimerManager::Tick()
{
	Thread::GuardLock lock( &m_lock );
	for ( auto it = m_list.begin() ; it != m_list.end() ; )
	{
		auto temp = it++;
		Timer* timer = *temp;

		(timer->m_counter < m_delay) ? (timer->m_counter = 0) : (timer->m_counter -= m_delay);
		if ( 0 == timer->m_counter )
		{
			if ( timer->m_handle )  
				timer->m_handle(timer,timer->m_param);  

			if ( Timer::TIMER_TYPE_ONCE == timer->m_type )  
			{  
				m_list.erase( temp );  
				timer->m_status = Timer::TIMER_STATUS_TIMEOUT;  
			}  
			else if( Timer::TIMER_TYPE_CIRCLE == timer->m_type )   
				timer->m_counter = timer->m_interval;
			else
				g_log.Fatal( "Timer type is fatal ! type:%d", timer->m_type );
		} 
	}
}

void TimerManager::Process()
{
	m_start = true;
	while ( m_start )
	{
		Time::SleepMsec( m_delay );
		Tick();
	}
}