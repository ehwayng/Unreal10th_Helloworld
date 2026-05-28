#include "Utils.h"
#include <float.h>
#include <math.h>


bool IfFloatEqual(float Num1, float Num2)
{
	return fabsf; (Num1 - Num2) <= FLT_EPSILON;		// 절댓값이 EPSION(엄청 작은 수)보다 작으면 참
}
