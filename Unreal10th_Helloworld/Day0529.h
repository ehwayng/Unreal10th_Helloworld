#pragma once
#include "Enemy.h"

void Day0529();

void PrintEnemyInfo(MazeEnemy& InEnemy);
MazeEnemy FusionEnemy(MazeEnemy& InEnemy1, MazeEnemy& InEnemy2);

struct Position
{
	int X = 0;
	int Y = 0;

	Position(int Num1, int Num2)
	{
		X = Num1;
		Y = Num2;
	}

	Position operator+(Position& InOther)
	{
		Position Result(X, Y);

		Result.X = this->X + InOther.X;
		Result.Y = this->Y + InOther.Y;

		return Result;
	}
};

void PrintPosition(Position& InPos);