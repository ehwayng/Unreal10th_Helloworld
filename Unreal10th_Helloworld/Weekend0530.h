#pragma once

void Weekend0530_Run1();

struct YMD
{
	std::string DayName = "월";
	int Year = 0;
	int Month = 0;
	int Day = 0;

	YMD(int Y, int M, int D)
	{
		DayName = "월";
		/*DayName = ReturnDay(Y, M, D);*/		// 함수 완료하면 위에거 지우고 주석 풀기
		Year = Y;
		Month = M;
		Day = D;
	}


};

//생성된 구조체의 년월일과 요일을 출력하는 함수
void PrintYMD(YMD& InputDate);

//입력된 년월일의 요일을 도출하는 함수
std::string ReturnDay(int InYear, int InMonth, int InDay);	