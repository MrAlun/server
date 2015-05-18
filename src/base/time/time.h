#ifndef _TIME_H_
#define _TIME_H_

#include "public.h"


class Time
{
public:
	Time();
	~Time();

	static void SleepMsec( int64 msec );

	void Refresh();

	int32 Year() const;
	int32 Month() const;
	int32 Day() const;
	int32 Hour() const;
	int32 Minute() const;
	int32 Second() const;

	int64 CpuClock() const;

	int32 WeekDay() const;
	int32 YeayDay() const;
	int64 Seconds() const;
	int32 Minutes() const;
	int32 Days() const;

	int8 Zone() const;
	int32 ZoneSecond() const;

	string AsString() const;

	void Abjust( int64 time = 0 );

protected:
	void CasheClock();
	void CasheTime();

private:
	int32	m_year;				//�꣨��ݣ���2011��
	int32	m_month;			//�£��·ݣ�1 -- 12��
	int32	m_day;				//�գ����ڣ�1 -- 31��
	int32	m_hour;			//ʱ��Сʱ��0 -- 23��
	int32	m_minute;			//�֣����ӣ�0 -- 59��
	int32	m_second;			//�루���ӣ�0 -- 59��

	int32	m_wday;			//���ڼ���0�������죬1������һ ...��
	int32	m_yday;			//����ĵڼ���

	int64	m_utc_time;		//��ǰ��UTCʱ�䣨��ϵͳʱ�䣬�ڲ�����ģ�
	int64	m_cpu_clock;		//ϵͳ�����ĺ�����

	int32	m_zone_second;	//ʱ��

	bool	m_is_tick;			//�Ƿ���Ҫ�ۼ�
	int64	m_tick_cache;		//�����ۼӺ�����ۼ���
};

#endif//_TIME_H_
