#include <iostream>
#include <string>
#include "FixedStack.h"
using namespace std;



//void FixedStack::Push(int InChar)
//{
//	if (TopIndex >= 10) //스택 꽉 참
//	{
//		printf("스택이 꽉 찼습니다!\n");
//		return;
//	}
//	Data[TopIndex] = InChar;
//	TopIndex++;
//}
//
//int FixedStack::Pop()
//{
//	if (TopIndex <= 0)	//스택 텅 빔
//	{
//		printf("스택이 비었습니다!\n");
//		return;
//	}
//	TopIndex--;
//	int Result = Data[TopIndex];
//	return Result;
//}
//
//bool FixedStack::IsEmpty()
//{
//	return TopIndex == 0;
//}


//==================================================




void DynamicStack::Push(int InSize, char* InStr)
{
	Data[TopIndex] = InStr[TopIndex];
	TopIndex++;
}

int DynamicStack::Pop()
{
	TopIndex--;
	int Result = Data[TopIndex];
	return Result;
}


