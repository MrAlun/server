#ifndef _MATH_H_
#define _MATH_H_

#include <vector>

#include "public.h"


namespace Math
{

int32 MCD( int32 n, int32 m );				// ���Լ�� max common divisor

int32 MCD( std::vector< int32 >& array );	// ���Լ��

}/* end of Math */

#endif//_MATH_H_
