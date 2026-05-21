#include <stdio.h>
#include <time.h>
#include "Day0521_practice2.h"

srand(time(0));

int PlayerDice(int num)
{
	int Result = rand() % 6 + 1;
	return Result;
}
