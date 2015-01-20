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

	int32 Year();
	int32 Month();
	int32 Day();
	int32 Hour();
	int32 Minute();
	int32 Second();
	int32 WeekDay();
	int32 YeayDay();
	int32 Seconds();
	int32 Minutes();

	void Abjust( int32 time = 0 );

protected:
	void CasheClock();
	void CasheTime();

private:
	int32	m_year;			//�꣨��ݣ���2011��
	int32	m_month;		//�£��·ݣ�1 -- 12��
	int32	m_day;			//�գ����ڣ�1 -- 31��
	int32	m_hour;			//ʱ��Сʱ��0 -- 23��
	int32	m_minute;		//�֣����ӣ�0 -- 59��
	int32	m_second;		//�루���ӣ�0 -- 59��

	int32	m_wday;			//���ڼ���0�������죻1������һ ...��
	int32	m_yday;			//����ĵڼ���

	int32	m_time;			//��ǰ��UTCʱ�䣨��ϵͳʱ�䣬�ڲ�����ģ�
	int64	m_pass;			//ϵͳ�����ĺ�����

	bool	m_is_cumulation;//�Ƿ���Ҫ�ۼ�
	int64	m_cumulation;	//�����ۼӺ�����ۼ���

	int32	m_zone_second;
};

#endif//_TIME_H_
