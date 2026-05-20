// Unreal10th_Helloworld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <time.h>
//#include <random> - C++용 랜덤...

using namespace std;

int main()
{
	// 간단실습
	
	// 1. 가위바위보 게임 - 3선승제 / enum 활용
	printf("<가위바위보 게임>\n");

	srand(time(0));
	int botRPS;
	int playerRPS = 0;
	int result = 0;	// 0=비김 1=플레이어승 2=컴퓨터승

	enum RPS
	{
		Scissors = 1,
		Rock,
		Paper
	};

	while (result != 0)
	{
		printf("[1] 가위  [2] 바위  [3] 보\n무엇을 낼지 숫자로 입력하세요 : ");
		cin >> playerRPS;
		botRPS = rand() % 3 + 1;
		if (botRPS = playerRPS)
		{
			if (botRPS == 1)
			{
			printf("Bot : 가위 / Player : 가위\n");
			}
			else if (botRPS == 2)
			{
			printf("Bot : 바위 / Player : 바위\n");
			}
			else
			{
			printf("Bot : 보 / Player : 보\n");
			}
		result = 0;
		printf("비겼습니다!\n\n");
		}
		else if (botRPS == 1)
		{
			if (playerRPS == 2)
			{
				printf("Bot : 가위 / Player : 바위\n");
				result = 1;
				printf("승리했습니다!^^\n\n");
			}
			else
			{
				printf("Bot : 가위 / Player : 보\n");
				result = 2;
				printf("패배했습니다!ㅠㅠ\n\n");
			}
		}
		else if (botRPS == 2)
		{
			if (playerRPS == 1)
			{
				printf("Bot : 바위 / Player : 가위\n");
				result = 2;
				printf("패배했습니다!ㅠㅠ\n\n");
			}
			else
			{
				printf("Bot : 바위 / Player : 보\n");
				result = 1;
				printf("승리했습니다!^^\n\n");
			}
		}
		else
		{
			if (playerRPS == 1)
			{
				printf("Bot : 보 / Player : 가위\n\n");
				result = 1;
				printf("승리했습니다!^^\n\n");
			}
			else
			{
				printf("Bot : 보 / Player : 바위\n\n");
				result = 2;
				printf("패배했습니다!ㅠㅠ\n\n");
			}

		}

	}

	//실습과제

	printf("1. 캐릭터 상태 변환 구현\n");

	enum condition
	{
		Jump,
		Attack,
		Standby,
		Invincible
	};

	int playerCondition = Standby;
	printf("현재 플레이어는 [%s] 상태입니다.\n", playerCondition);




	//// 랜덤
	//srand(time(0));		// !랜덤의 시드값을 현재 시간으로 설정하기! (프로그램 실행할 때 한번만 하면 됨)

	//int RandomNumber;
	//int TestCount = 10000000;
	//int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
	//for (int i = 0; i < TestCount; i++)
	//{
	//	RandomNumber = rand() % 6 + 1;	// 1~6이 랜덤으로 골라지게 됨	// rand() - 0에서 RandMax 사이에서 랜덤하게 나옴
	//	//printf("Random : %d\n", RandomNumber);
	//	switch (RandomNumber)
	//	{
	//	case 1 :
	//		num1++;
	//		break;
	//	case 2 :
	//		num2++;
	//		break;
	//	case 3 :
	//		num3++;
	//		break;
	//	case 4 :
	//		num4++;
	//		break;
	//	case 5 :
	//		num5++;
	//		break;
	//	case 6 :
	//		num6++;
	//		break;
	//	default :
	//		printf("ERROR!! ERROR!! ERROR!!\n");
	//		break;
	//	}
	//}
	//printf("num1: [%d]\tnum2: [%d]\tnum3: [%d]\tnum4: [%d]\tnum5: [%d]\tnum6: [%d]", num1, num2, num3, num4, num5, num6);
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
