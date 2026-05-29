#include "Utils.h"
#include <float.h>
#include <math.h>
#include <stdlib.h>


bool IfFloatEqual(float Num1, float Num2)
{
	return fabsf; (Num1 - Num2) <= FLT_EPSILON;		// 절댓값이 EPSION(엄청 작은 수)보다 작으면 참
}

float GetRandom()
{
	return rand() / (float)RAND_MAX;	// 0.0f ~ 1.0f
}

int GetRandomRange(int Min, int Max)
{
	return Min + rand() % (Max - Min + 1);		// Min ~ Max (양끝 포함)
}
