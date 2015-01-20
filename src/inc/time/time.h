#ifndef _TIME_H_
#define _TIME_H_

class Time
{
public:
	Time();
	~Time();

private:
	uint32			m_year;			//�꣨��ݣ���2011��
	uint32			m_month;		//�£��·ݣ�1 -- 12��
	uint32			m_mday;		//�գ����ڣ�1 -- 31��
	uint32			m_hour;		//ʱ��Сʱ��0 -- 23��
	uint32			m_minute;		//�֣����ӣ�0 -- 59��
	uint32			m_second;		//�루���ӣ�0 -- 59��
	uint32			m_wday;		//���ڼ���0�������죻1������һ ...��
	uint32			m_yday;		//����ĵڼ���

	uint32			m_time;		//��ǰ��UTCʱ�䣨��ϵͳʱ�䣬�ڲ�����ģ�
	uint64			m_run_time;	//����CPU�����ڱ���Ľ���/ϵͳ�����ĺ�����

	uint64			m_Cumulation;		//�����ۼӺ�����ۼ���
	bool			m_bIsCumulatino;	//��־�Ƿ���Ҫ�ۼ�
	uint32			m_TimeZoneSecond;	//����ʱ��
};

#endif//_TIME_H_
