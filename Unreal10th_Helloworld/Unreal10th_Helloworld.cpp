// Unreal10th_Helloworld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	// 1. 세 수 중 최댓값과 최솟값 찾기
	//		- 3개의 정수를 입력받아, 그중 가장 큰 수와 가장 작은 수를 출력
	// 2. 세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기
	//		- 조건 : 삼각형이 되려면 '가장 긴 변의 길이 < 나머지 두 변의 길이의 합'이어야 함.
	// 3. 미니 계산기
	//		- 두 개의 정수와 하나의 연산자(+, -, *, / )를 입력받아 결과를 출력
	//		- 단, 나눗셈에서 0으로 나누려고 하면 "0으로 나눌 수 없습니다"라는 에러 메시지를 출력
	// 4. 윤년 판별기
	//		- 연도(예 : 2024)를 입력받아 그 해가 윤년인지 평년인지 출력
	//		- 윤년의 조건 :
	//			연도가 4로 나누어 떨어지면 윤년이다.
	//			하지만 100으로 나누어 떨어지면 평년이다.
	//			그럼에도 400으로 나누어 떨어지면 윤년이다.

	printf("1. 최댓값/최솟값 찾기\n");
	int num1 = 0, num2 = 0, num3 = 0;
	printf("세 가지 숫자를 입력하세요 : ");
	cin >> num1 >> num2 >> num3;
	if (num1 >= num2 && num1 >= num3)
	{
		printf("최댓값은 [%d] 입니다.\n", num1);
		if (num2 < num3)
		{
			printf("최솟값은 [%d] 입니다.\n", num2);
		}
		else
		{
			printf("최솟값은 [%d] 입니다.\n", num3);
		}
	}
	else if (num2 >= num1 && num2 >= num3)
	{
		printf("최댓값은 [%d] 입니다.\n", num2);
		if (num1 < num3)
		{
			printf("최솟값은 [%d] 입니다.\n", num1);
		}
		else
		{
			printf("최솟값은 [%d] 입니다.\n", num3);
		}
	}
	else if (num3 >= num1 && num3 >= num2)
	{
		printf("최댓값은 [%d] 입니다.\n", num3);
		if (num1 < num2)
		{
			printf("최솟값은 [%d] 입니다.\n", num1);
		}
		else
		{
			printf("최솟값은 [%d] 입니다.\n", num2);
		}
	}
	
	printf("\n\n");

	printf("2. 삼각형 조건 판별\n");
	int line1 = 0, line2 = 0, line3 = 0;
	printf("세 개의 선분 길이를 입력하세요(cm) : ");
	cin >> line1 >> line2 >> line3;
	if (line1 >= line2 && line1 >= line3)
	{
		if (line1 < line2 + line3)
		{
			printf("이 선분들로 삼각형을 만들 수 있습니다.\n");
		}
		else
		{
			printf("이 선분들로는 삼각형을 만들 수 없습니다.\n");
		}
	}
	else if (line2 >= 1 && line2 >= line3)
	{
		if (line2 < line1 + line3)
		{
			printf("이 선분들로 삼각형을 만들 수 있습니다.\n");
		}
		else
		{
			printf("이 선분들로는 삼각형을 만들 수 없습니다.\n");
		}
	}
	else if (line3 >= line1 && line3 >= line2)
	{
		if (line3 < line1 + line2)
		{
			printf("이 선분들로 삼각형을 만들 수 있습니다.\n");
		}
		else
		{
			printf("이 선분들로는 삼각형을 만들 수 없습니다.\n");
		}
	}

	printf("\n\n");

	printf("3. 미니계산기\n");
	float numA = 0.0f, numB = 0.0f;
	char oper = 'a';
	printf("두 개의 정수를 입력하세요 : ");
	cin >> numA >> numB;
	printf("+, - , * , / 중 사용할 연산자를 입력하세요 : ");
	cin >> oper;
	if (numB == 0)
	{
		printf("0으로 나눌 수 없습니다.\n");
	}
	else
	{
		printf("%.0f %c %.0f\n", numA, oper, numB);
		if (oper == '+')
		{
			printf("연산의 결과값은 [%.0f] 입니다.\n", numA + numB);
		}
		else if (oper == '-')
		{
			printf("연산의 결과값은 [%.0f] 입니다.\n", numA - numB);
		}
		else if (oper == '*')
		{
			printf("연산의 결과값은 [%.0f] 입니다.\n", numA * numB);
		}
		else if (oper == '/')
		{
			float div = numA / numB;
			printf("연산의 결과값은 [%.2f] 입니다.\n", div);
		}
	}

	printf("\n\n");

	printf("3. 윤년 판별기\n");
	int year = 0;
	printf("윤년인지 판별할 연도를 입력하세요 : ");
	cin >> year;
	int yearF = year % 4;
	int yearH = year % 100;
	int year4H = year % 400;
	if ((yearF == 0 && yearH != 0) || year4H == 0)
	{
		printf("%d년은 윤년입니다.\n", year);
	}
	else
	{
		printf("%d년은 평년입니다.\n", year);
	}

	printf("\n\n\n\n");
}





// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
