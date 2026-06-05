#include "Weekend0606.h"
#include "Utils.h"


//맵 배열 및 좌표 생성
	const int MapSize = 10;
	int Ycoordinate[10] = { 1,2,3,4,5,6,7,8,9,10 };		// Y축 좌표 배열

	int TrueMap[MapSize][MapSize] = { 0, };		// 실제 함선이 배치된 맵
	int PlayerMap[MapSize][MapSize] =			// 플레이어에게 보여질 맵 (지금은 출력 확인용)
	{
		{1,2,1,0,0,1,0,0,0,1},
		{0,1,2,0,0,0,1,1,0,0},
		{1,2,1,0,0,1,0,0,0,1},
		{1,2,1,0,0,1,0,0,0,1},
		{0,1,2,0,0,0,1,1,0,0},
		{0,1,2,0,0,0,1,1,0,0},
		{1,2,1,0,0,1,0,0,0,1},
		{0,1,2,0,0,0,1,1,0,0},
		{1,2,1,0,0,1,0,0,0,1},
		{0,1,2,0,0,0,1,1,0,0}
	};

	int PlayCount = 0;			//현재 공격 횟수
	const int MaxCount = 30;	//최대 공격횟수

void Weekend0606()
{
	//10x10 맵 만들고, 함선 랜덤 배치시키기
	//플레이어에게 출력되는 맵에는 함선 안 보이고 위치만 정해져 있음 (원하면 둘 다 볼 수 있도록 두가지 함수 세팅)

	//while 문 : 30회 이내/모든 함선 격침되지 않는 조건 안에서 반복
		// 1. 좌표 입력 2. 결과 변수 반영 및 출력(텍스트, 맵)
		// 중복 공격 막기
		// 남은 공격 횟수, 남은 함선 수 안내

	//종료 시, 승리/패배 판별 및 출력
		// 패배 시 함선 위치 출력

	//===================================================================

	//맵 생성 및 초기화
	//함선 배치 (True 맵에, Player 맵은 초기화 상태)

	//공격턴 반복
	//공격한 좌표의 [TrueMap] 인덱스가
	//		0일 시 > [PlayerMap]의 해당 좌표를 2로 변경 후 출력 (공격실패 출력)
	//		1일 시 > [PlayerMap]의 해당 좌표도 1로 변경 후 출력 (공격성공 출력) 
	//남은 횟수/갯수 출력

	//종료 시 결과와 TrueMap 출력




	//플레이어 맵 출력
	PrintMap();

	while (!IsGameOver)
	{ 
		int SelectX = 0;
		std::string SelectY;
		printf("공격할 좌표를 알파벳 → 숫자 순으로 입력해 주세요 : \n");	
		std::cin >> SelectY >> SelectX;

		//입력된 알파벳 숫자 좌표로 치환 필요
	}
	
}



void RandomShip()
{
	//함선 랜덤 배치 (총 4개)
	//100개의 인덱스 중 14개 랜덤으로 선택
	//5 4 3 2 가 각 덩이씩 가로 혹은 세로로 연속되어야 함

	// 1순위
	// 10개를 6개로 취급하고 하나를 랜덤선택하면 사이즈 5의 배를 하나 만들 수 있음
	// 7개에서 1개 랜덤선택 > 4칸 배
	// 8개 중 1 > 3칸 배, 9개 중 1 > 2칸 배

	// 1. 20개 중 1줄 선택, 그 줄에서 6개중1 선택 > 5칸 배
	// 2. 20개 중 1줄 선택,
	//				if (그 줄에 5칸 배가 있다면)
	//					if(끝에 붙어있다면 한칸 띄우고 배치)
	//					else(아니라면 배치불가 else로 넘어가라)
	//				else (그 줄에 5칸 배가 없다면)
	//					7개중 1 선택 
	// 3. 20개 중 1줄 선택,
	//				if (그 줄에 5칸, 4칸이 같이 있다면)
	//					불가. 걍 넘어가라.
	//				else(5칸만 있다면)
	//					if(한쪽 여백이 1칸이거나 딱 붙어 있으면)
	//					배치 가능. 여백 2칸이상이면 다시 넘어가야 함.
	//				else(4칸만 있다면)
	//					if(정중앙에 있다면) 배치불가
	//					else(한쪽으로 조금이라도 쏠렸다면) 배치 가능
	//				else(아무것도 없다면)
	//					8개중 1 선택
	// 4. 20개 중 1줄 선택
	//				if (그 줄에 5칸, 4칸이 같이 있거나 5칸, 3칸이 같이 있거나 4칸, 3칸이 같이 있다면)
	//					불가. 걍 넘어가라.
	//				else (5칸만 있다면)
	//				else (4칸만 있다면)
	//				else (3칸만 있다면)
	//				else (아무것도 없다면)

	// 선택된 함선 인덱스 => 1
}

bool IsGameOver()	// (모든 함선 격추&&플레이카운트 30 이하) || (플레이카운트 30 && 함선 남아있는 경우)
{
	return false;
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

void PrintResult()
{
}

void PrintRemaining()
{
}
