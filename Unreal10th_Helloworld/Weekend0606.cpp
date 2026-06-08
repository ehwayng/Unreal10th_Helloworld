#include "Weekend0606.h"
#include "Utils.h"


//맵 배열 및 좌표 생성
	const int MapSize = 10;
	int Ycoordinate[10] = { 1,2,3,4,5,6,7,8,9,10 };		// Y축 좌표 배열

	int TrueMap[MapSize][MapSize] = { 0, };		// 실제 함선이 배치된 맵
	int PlayerMap[MapSize][MapSize] = { 0, };	// 플레이어에게 보여질 맵

	int PlayCount = 0;			//현재 공격 횟수
	const int MaxCount = 30;	//최대 공격 횟수
	int HitCount = 0;			//맞춘 횟수 : 14회 달성시 승리
	int RemainingShip = 4;		//남은 함선
	bool IsGameOver = false;	//게임 종료 조건
	
void Weekend0606()
{
	// 각 맵 출력 코드
	// PrintMap();
	// PrintTrueMap();

	//1. 함선 랜덤 배치
	RandomShip();

	//2. 게임 시작, 게임 종료 조건 만족 전까지 반복
	while (!IsGameOver)
	{ 
		int SelectX = 0;
		std::string SelectY;
		
		PrintMap();
		PrintRemaining();	//남은공격횟수와 남은 함선수 출력
		printf("\n공격할 좌표를 알파벳(A~J), 숫자(1~10) 순으로 입력해 주세요 : \n");	
		std::cin >> SelectY >> SelectX;

		char CharY = SelectY[0];
		int AttackX = SelectX - 1;
		int AttackY = CharY - 'A';	//아스키코드 이용

		//범위 밖의 좌표 입력시 오류
		if (AttackY < 0 || AttackY >= MapSize || AttackX < 0 || AttackX >= MapSize)
		{
			printf("\n입력 오류! 대문자 A~J, 숫자 1~10 사이로 입력해주세요.\n");
			continue;
		}
		//공격 중복 오류
		if (PlayerMap[AttackY][AttackX] != 0)
		{
			printf("\n이미 공격한 좌표입니다. 다른 곳을 선택하세요.\n");
			continue;
		}

		PlayCount++;
		
		if (TrueMap[AttackY][AttackX] > 0)		//명중 성공 (TrueMap의 2,3,4,5)
		{
			int HittedShip = TrueMap[AttackY][AttackX];	//명중한 함선의 사이즈 기억
			printf("\n명중! 함선을 파괴했습니다.\n");
			PlayerMap[AttackY][AttackX] = 1;	//플레이어 맵에 명중 표시
			HitCount++;
			PrintMap();

			bool DestroyedShip = true; //함선 하나가 격침되었는지 판별
			for (int i = 0; i < MapSize; i++)
			{
				for (int j = 0; j < MapSize; j++)
				{
					// TrueMap에 있는 배 중, PlayerMap에 명중(1) 표시가 안 된 곳이 있는지 확인
					if (TrueMap[i][j] == HittedShip && PlayerMap[i][j] != 1)
					{
						DestroyedShip = false;	//격침 아님
						break;
					}
				}
				if (!DestroyedShip) break;
			}

			// 같은 사이즈의 칸을 다 명중하면 격침
			if (DestroyedShip)
			{
				printf("\n크기 %d의 함선이 격침되었습니다!\n", HittedShip);
				RemainingShip--;	//남은 함선 수 감소
			}
		}
		else
		{
			printf("\n실패! 빗나갔습니다.\n");
			PlayerMap[AttackY][AttackX] = 2;	//플레이어 맵에 실패 표시
			PrintMap();
		}

		//게임 종료 조건
		if (HitCount == 14)
		{
			printf("\n플레이어 승리! 모든 함선을 격침시켰습니다!\n");
			IsGameOver = true;
		}
		else if ((MaxCount - PlayCount) == 0)
		{
			printf("\n플레이어 패배! 제한 횟수를 모두 소진했습니다.\n실제 함선 위치는 다음과 같습니다.\n");
			IsGameOver = true;
			PrintTrueMap();
		}
	}
}

void RandomShip()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;
	srand(Seed);

	int ShipSize[4] = { 2,3,4,5 };

	for (int Size : ShipSize)
	{
		bool ShipPlaced = false;

		while (!ShipPlaced)
		{
			int Direction = rand() % 2;    // 0 또는 1 (방향)
			int ShipX = rand() % 10;     // 0 ~ 9 (X 좌표)
			int ShipY = rand() % 10;     // 0 ~ 9 (Y 좌표)

			bool CanPlace = true;

			// 배치 가능 여부 판별	
			if (Direction == 0)	// 가로
			{
				if (ShipX + Size > MapSize)
					CanPlace = false;
				else
				{
					for (int i = 0; i < Size; i++)
					{
						if (TrueMap[ShipY][ShipX + i] != 0)
						{ CanPlace = false; break; }
					}
				}
			}
			else   //세로
			{
				if (ShipY + Size > MapSize) CanPlace = false;
				else {
					for (int i = 0; i < Size; i++) {
						if (TrueMap[ShipY + i][ShipX] != 0)
						{ CanPlace = false; break; }
					}
				}
			}

			// 통과시 배치
			if (CanPlace)
			{
				if (Direction == 0)
				{
					for (int i = 0; i < Size; i++)
						TrueMap[ShipY][ShipX + i] = Size;	//함선의 위치를 사이즈로 표기
				}
				else
				{
					for (int i = 0; i < Size; i++)
						TrueMap[ShipY + i][ShipX] = Size;
				}
				ShipPlaced = true;
			}
		}
	}
}

void PrintMap()
{
	printf("[BattleShip] 숨은 함선을 격침하라!\n\n");
	printf("   1  2  3  4  5  6  7  8  9  10\n");		// X축 좌표 표시
	for (int i = 0; i < MapSize; i++)
	{
		/*printf("%2d ", Ycoordinate[i]);	*/			// Y축 좌표 표시
		if (Ycoordinate[i] == 1)
			printf("A ");
		else if (Ycoordinate[i] == 2)
			printf("B ");
		else if (Ycoordinate[i] == 3)
			printf("C ");
		else if (Ycoordinate[i] == 4)
			printf("D ");
		else if (Ycoordinate[i] == 5)
			printf("E ");
		else if (Ycoordinate[i] == 6)
			printf("F ");
		else if (Ycoordinate[i] == 7)
			printf("G ");
		else if (Ycoordinate[i] == 8)
			printf("H ");
		else if (Ycoordinate[i] == 9)
			printf("I ");
		else if (Ycoordinate[i] == 10)
			printf("J ");

		for (int j = 0; j < MapSize; j++)
		{
			if (PlayerMap[i][j] == 0)		//건드리지 않은 칸					//더 그리드가 이쁜 특수문자를 찾아보자...
				printf(" ■ ");
			if (PlayerMap[i][j] == 1)		//공격 성공한 칸(격침된 칸)
				printf(" ▨ ");
			if (PlayerMap[i][j] == 2)		//공격 실패한 칸(쐈더니 빈칸)
				printf(" □ ");
		}
		printf("\n");
	}
	printf("\n");
}

void PrintTrueMap()
{
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			printf("%3d ", TrueMap[i][j]);
		}
		printf("\n");
	}
}

void PrintRemaining()
{
	printf("============================================\n");
	printf("[남은 공격] %d회 / [남은 함선] %d개\n", MaxCount - PlayCount, RemainingShip);
	printf("============================================\n");
}
