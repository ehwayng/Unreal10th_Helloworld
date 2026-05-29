#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Utils.h"
#include "Weekend0530.h"

using namespace std;

void Weekend0530_Run1()
{
	int Y = 0, M = 0, D = 0;
	printf("요일을 도출할 날짜를 연도, 월, 일 순으로 입력하세요 : \n");
	cin >> Y >> M >> D;
	YMD Date(Y, M, D);		// 입력한 날짜를 기준으로 구조체 생성
	
	// PrintYMD(Date);
	YMD Test(2000, 2, 2);	// 잘 출력되는지 테스트용 (완성 후 지울거임)
	PrintYMD(Test);
}


//생성된 구조체의 년월일과 요일을 출력하는 함수
void PrintYMD(YMD& InputDate)
{
	printf("입력한 %d년 %d월 %d일은 [%s요일]입니다.\n", InputDate.Year, InputDate.Month, InputDate.Day, InputDate.DayName.c_str());
}

//입력된 년월일의 요일을 계산하는 함수
std::string ReturnDay(int InYear, int InMonth, int InDay)
{
	std::string Result;

	//연도부터 더해놓기
	int SumDay = (InYear - 1) * 365;

	//윤년 판별후 월 더하기
	int InYear4 = InYear % 4, InYear100 = InYear % 100, InYear400 = InYear % 400;
	if ((InYear4 == 0 && InYear100 != 0) || InYear400 == 0)		// 윤년일 경우
	{
		SumDay += (InMonth - 1) * 30;		// 수정 필요 (각 월별로 날짜 다른것 처리)
	}
	else    //평년일 경우
	{
		SumDay += (InMonth - 1) * 30;		// 수정 필요
	}

	//날짜 더해서 총 며칠이 지났는지 도출 후 요일 구하기
	SumDay += InDay;
	if (SumDay % 7 == 0)
	{
		Result = "일";
	}
	else if (SumDay % 7 == 1)
	{
		Result = "월";
	}
	else if (SumDay % 7 == 2)
	{
		Result = "화";
	}
	else if (SumDay % 7 == 3)
	{
		Result = "수";
	}
	else if (SumDay % 7 == 4)
	{
		Result = "목";
	}
	else if (SumDay % 7 == 5)
	{
		Result = "금";
	}
	else
	{
		Result = "토";
	}

	return Result;
}

