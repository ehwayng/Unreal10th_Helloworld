#pragma once
//#include "MazeCommon.h"
//#include "Player.h"


enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3
};

enum MoveDirection
{
	DirNone		= 0,			
	DirUP		= 1 << 0,		// 1
	DirDown		= 1 << 1,		// 2
	DirLeft		= 1 << 2,		// 4
	DirRight	= 1 << 3		// 8
};

enum RandomIncounterType
{
	RI_None = 0,	// 아무일 없음
	RI_Battle,		// 전투
	RI_Heal,		// 회복
	RI_Treasure		// 보물 찾음(돈)
};

// constexpr; : 컴파일 타임에 결정되는 상수
// constexpr int MazeHeight = 10;
// const int MazeHeight = 10;
// const int MazeWidth = 20;

// 랜덤 인카운터 종류별 확률
const float BattleRate = 0.1f;
const float HealRate = 0.1f;
const float TreasureRate = 0.1f;

// MazeTile 표시용
const char* const ShapePlayer = "P";
const char* const ShapeWall = "#";
const char* const ShapePath = ".";
const char* const ShapeStart = "S";
const char* const ShapeEnd = "E";

// 미로 정보를 저장할 구조체
struct MazeData
{
	unsigned int Width = 0;
	unsigned int Height = 0;
	int* Data = nullptr;

	MazeData() = default;
};

// extern : 실제 선언은 아니고 다른 곳에 이런 변수/함수 등이 존재한다고 알려주는 것
// extern int Maze[MazeHeight][MazeWidth]

void Weekend0523();

// 게임 시작 함수
void Weekend0523_Dungeon();

// 시작 위치 찾는 함수
void FindStart(int& OutX, int& OutY);

// 미로를 출력하는 함수
void PrintMaze(int PlayerX, int PlayerY);

// 플레이어의 현재 상태를 출력하는 함수
void PrintPlayerState(int Health, int MaxHealth, int Money);

// 플레이어가 도착점에 도착했는지 확인하는 함수
bool IsGoal(int PlayerX, int PlayerY);

// 이동할 수 있는 방향을 출력하고 그 결과를 비트플래그로 반환하는 함수
int PrintAvailableMoves(int PlayerX, int PlayerY);

// 해당 위치가 벽인지 아닌지 확인하는 함수
bool IsWall(int X, int Y);

// 이동 방향을 입력받고 해당 방향을 리턴하는 함수
MoveDirection GetMoveInput(int PlayerX, int PlayerY);

// 랜덤 인카운터(전투) 발생 여부를 체크하는 함수
RandomIncounterType RandomIncounter();

// 전투 랜덤 인카운터 이벤트 처리 함수
bool Battle(int& PlayerHealth);

// 플레이어 체력회복 랜덤 인카운터 이벤트 처리 함수
void Heal(int& PlayerHealth, int MaxHealth);

// 플레이어 보물발견 랜덤 인카운터 이벤트 처리 함수
void Treasure(int& PlayerMoney);

// 자리수 분리해서 합치기(입력은 인티저로 제한)
int Getsume(int Number);

// 자리수 분리해서 합치기(입력은 자리수 제한 없음)
int Getsum(const char* NumberString);

// 특정 위치의 Maze 타일 정보를 리턴하는 함수
int GetMazeData(int X, int Y);

// 특정 위치의 Maze 타일 정보를 세팅하는 함수
void SetMazeData(int X, int Y);