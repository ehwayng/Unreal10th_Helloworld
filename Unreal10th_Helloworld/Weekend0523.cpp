#include <iostream>
#include "Utils.h"
#include "Weekend0523.h"

using namespace std;

// 미로 배열
//int Maze[MazeHeight][MazeWidth] =
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//	{1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1},
//	{0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
int* Maze = nullptr;

void Weekend0523()
{
}

void Weekend0523_Dungeon()
{
}

void FindStart(int& OutX, int& OutY)
{
}

void PrintMaze(int PlayerX, int PlayerY)
{
}

void PrintPlayerState(int Health, int MaxHealth, int Money)
{
}

bool IsGoal(int PlayerX, int PlayerY)
{
	return false;
}

int PrintAvailableMoves(int PlayerX, int PlayerY)
{
	return 0;
}

bool IsWall(int X, int Y)
{
	return false;
}

MoveDirection GetMoveInput(int PlayerX, int PlayerY)
{
	return MoveDirection();
}

RandomIncounterType RandomIncounter()
{
	return RandomIncounterType();
}

bool Battle(int& PlayerHealth)
{
	return false;
}

void Heal(int& PlayerHealth, int MaxHealth)
{
}

void Treasure(int& PlayerMoney)
{
	const int TreasureMin = 100;
	const int TreasureMax = 500;

	int TreasureAmount = GetRandomRange(TreasureMin, TreasureMax);
	printf("보물을 발견했습니다.\n[%d] 만큼의 돈을 획득합니다.\n", TreasureAmount);
	PlayerMoney += TreasureAmount;
}

int Getsume(int Number)
{
	return 0;
}

int Getsum(const char* NumberString)
{
	return 0;
}

int GetMazeData(int X, int Y)
{
	return 0;
}

void SetMazeData(int X, int Y)
{
}
