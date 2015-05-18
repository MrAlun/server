#ifndef _IS_CLASS_H_
#define _IS_CLASS_H_

//ȷ��ĳ�������Ƿ�Ϊ������class,struct,union
template<typename T>
class ClassT
{  
private:
	typedef char One;
	typedef struct
	{
		char a[2];
	}Two;

	// C��������ʱʹ������汾������������һ��C�ĳ�Աָ��
	template<typename C>
	static One Check(int C::*); 

	// C�Ƿ�������ʱʹ������汾
	template<typename C>
	static Two Check(...); 

public:
	enum { Yes = sizeof(Check< T >( 0 )) == 1 }; //����������YesΪ1������������ʱYesΪ0
	enum { No =! Yes };
};

//���T�Ƿ��������ͣ���ģ��ʵ�η�ʽ��������
template< typename T >
bool IsClass()
{ 
	if( ClassT<T>::Yes )
		return true;

	return false;
}

//���T�Ƿ��������ͣ��Ժ�������ʵ�η�ʽ��������
template< typename T >
bool IsClassT( T& a )
{  
	return IsClass< T >();
}

#endif//_IS_CLASS_H_
