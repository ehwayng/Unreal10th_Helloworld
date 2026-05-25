#include <iostream>
#include "0524_Homework.h"

using namespace std;

void ArrayPrint(int* Array, int Length)
{
	printf("Array : [ ");
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}

void Homework02_Run()
{
	int number = 0;
	printf("숫자를 입력하세요 : \n");
	cin >> number;
	const int input = number;
	int digit = 1;					// 숫자를 10으로 나눈 값
	while (number / 10 != 0)		// 더 이상 안 나워질 때까지 반복
	{
		number = number / 10;
		digit++;
	}

	printf("입력된 숫자 %d는 %d자리 수 입니다.\n", input, digit);	// 자리수 도출

	int sum = 0;
	number = input;
	while (number / 10 != 0)
	{
		sum += (number % 10);
		number = number / 10;
	}
	sum += number;

	printf("각 자리수의 합은 %d입니다.\n", sum);
}

void Homework03_Run()
{
	//슬롯 머신 게임
	//시작 금액 10000
	//한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
	//같은 숫자 3개가 나오면 50배로 돌려 받는다.
	//만약 777이면 10000배 받음

	int money = 10000;
	printf("현재 소지금액 : 10000원\n");
	while (money >= 100)
	{
		int bet = 0;
		printf("베팅할 금액을 100원부터 입력하세요 : \n");
		cin >> bet;
		money -= bet;

		int Slot[3] = { 0, };
		Slot[0] = rand() % 3 + 5;
		Slot[1] = rand() % 3 + 5;
		Slot[2] = rand() % 3 + 5;
		ArrayPrint(Slot, 3);

		if (Slot[0] == Slot[1] && Slot[0] == Slot[2])
		{
			if (Slot[0] != 7)
			{
				printf("3개 숫자 일치! 베팅액의 50배를 얻습니다.\n");
				money += bet * 50;
				printf("소지금액 : %d", money);
			}
			else
			{
				printf("JackPot! 베팅액의 10000배를 얻습니다.\n");
				money += bet * 10000;
				printf("소지금액 : %d\n", money);
			}
		}
		else
		{
			printf("실패! 베팅액을 잃었습니다.\n소지금액 : %d\n", money);
		}
	}
	printf("최소 베팅 금액을 가지고 있지 않습니다.\n게임을 종료합니다.\n");

}

void Shuffle(int* Array, int Length)
{
	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];	// 값이 바뀌기 전 i의 값을 잃지 않기 위해 임시 저장
		Array[i] = Array[j];
		Array[j] = Temp;
	}
}

void Homework04_Run()
{
	//도둑 잡기 만들기
	//시작 금액 10000
	//한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
	//딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
	//플레이어는 딜러의 카드 중 한장을 선택한다.
	//만약 플레이어가 조커를 뽑있다면 플레이어의 승리.배팅 금액의 2배를 받는다.
	//플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.

	int money = 10000;
	printf("현재 소지금액 : 10000원\n");
	int Cards[3] = { 0, };
	while (money >= 100)
	{
		int bet = 0;
		printf("베팅할 금액을 100원부터 입력하세요 : \n");
		cin >> bet;
		if (bet < 100 || bet > money)
		{
			printf("잘못된 베팅 금액입니다. 다시 입력해주세요.\n");
			continue;
		}
		money -= bet;

		Cards[0] = Joker;
		Cards[1] = rand() % 11 + 1;
		Cards[2] = rand() % 11 + 1;
		while (Cards[1] == Cards[2])
		{
			Cards[2] = rand() % 11 + 1;
		}
		Shuffle(Cards, 3);			// 여기까지가 중복 제거하고 딜러 카드 뽑기&셔플
		printf("딜러가 카드를 뽑았습니다.\n[ 1 , 2 , 3 ]\n");

		while (true)
		{
			int Select = 0;
			printf("3개의 카드 중 하나를 선택하세요 : ");
			cin >> Select;
			if (Cards[Select - 1] == 0)
			{
				money += bet * 2;
				printf("승리! 베팅 금액의 2배를 획득합니다.\n");
				printf("현재 소지금액 : %d원\n", money);
			}
			else
			{
				int failSelect = 0;
				printf("조커를 뽑지 못했습니다.\n현재 소지금액 : % d원\n", money);
				printf("다음 2가지 중 선택하세요.\n1. 다음 게임 시작하기\n2. 배팅 금액의 2배를 지불하고 한번 더 선택하기\n");
				cin >> failSelect;
				if (failSelect == 1)				//다음게임 시작
				{
					printf("현재 금액 : % d원", money);
					break;
				}
				else if (failSelect == 2)						//2배 주고 한번더
				{
					bet *= 2;
					money -= bet;
					Shuffle(Cards, 3);
					printf("카드를 다시 섞었습니다.\n[ 1 , 2 , 3 ]\n3개의 카드 중 하나를 선택하세요 : ");
					cin >> Select;
					if (Cards[Select - 1] == 0)
					{
						money += bet * 2;
						printf("승리! 베팅 금액의 2배를 획득합니다.\n");
						printf("현재 소지금액 : %d원\n", money);
					}
					else 
					{
						printf("조커를 뽑지 못했습니다. 다음 2가지 중 선택하세요.\n1. 다음 게임 시작하기\n2. 배팅 금액의 2배를 지불하고 한번 더 선택하기");
						cin >> failSelect;
					}
				}
				else
				{
					printf("다시 선택하세요.\n");
					break;
				}
			}
		}
	}
}




void Homework05_Run()
{
	printf("4. 미로탈출게임\n\n");
	const int MazeRows = 10;
	const int MazeCols = 20;
	int Maze[MazeRows][MazeCols] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1},
		{1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1},
		{0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1}
	};

	// 미로 출력
	for (int i = 0; i < MazeRows; i++)
	{
		for (int j = 0; j < MazeCols; j++)
		{
			if (Maze[i][j] == 0)
			{
				printf(".");
			}
			else if (Maze[i][j] == 1)
			{
				printf("#");
			}
			else if (Maze[i][j] == 2)
			{
				printf("S");
			}
			else if (Maze[i][j] == 3)
			{
				printf("E");
			}
		}
		printf("\n");
	}



	// 플레이어 이동
	enum Move
	{
		None = 0,
		w,
		s,
		a,
		d
	};
	
	int i = 2, j = 2;
	int CurrentPosition = Maze[i][j];
	int PlayerMove = None;
	printf("\n이동할 방향을 선택하세요\nW(위↑), S(아래↓), A(왼쪽←), D(오른쪽→) : ");
	cin >> PlayerMove;

	while (CurrentPosition != Maze[9][15])
	{
		int PrePosition = 0;
		if (PlayerMove == w)
		{
			PrePosition = CurrentPosition;
			i += 1;
			PrePosition = 0;
			CurrentPosition = 2;
		}
		else if (PlayerMove == s)
		{
			PrePosition = CurrentPosition;
			i -= 1;
			PrePosition = 0;
			CurrentPosition = 2;
		}
		else if (PlayerMove == a)
		{
			PrePosition = CurrentPosition;
			j -= 1;
			PrePosition = 0;
			CurrentPosition = 2;
		}
		else if (PlayerMove == d)
		{
			PrePosition = CurrentPosition;
			j += 1;
			PrePosition = 0;
			CurrentPosition = 2;
		}
		else
		{
			printf("다시 입력해주세요.\n");
		}
	}
}
