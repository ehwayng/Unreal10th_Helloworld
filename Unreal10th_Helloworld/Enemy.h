#pragma once
#include <string>
#include "Utils.h"

struct MazeEnemy
{
	std::string Name = "고블린";
	int Health = 20;
	int AttackPowerMin = 5;
	int AttackPowerMax = 10;
	int Reward = 100;

	MazeEnemy()
	{
		Health = GetRandomRange(15, 25);
		AttackPowerMin = GetRandomRange(3, 7);
		AttackPowerMax = GetRandomRange(8, 12);
		Reward = GetRandomRange(80, 120);
	}
	MazeEnemy(const std::string& InName, int InLevel)
		: Name(InName)
	{
		Health *= InLevel;
		AttackPowerMin *= InLevel;
		AttackPowerMax *= InLevel;
		Reward *= InLevel;
	}

	// '+' 연산자를 오버로딩한다.
	// 결과는 MazeEnemy 타입으로 나온다.
	// 계산 대상은 나와 InOther.
	MazeEnemy operator+(const MazeEnemy& InOther) const		// 이 const는 멤버를 수정하지 않는다 (읽기전용이다)
	{
		// Health = 20;	 // const 때문에 안된다

		MazeEnemy Result;
		Result.Name = this->Name + InOther.Name;	// this : 자기 자신의 주소
		Result.AttackPowerMin = (AttackPowerMin + InOther.AttackPowerMin) / 2;
		Result.AttackPowerMax = (AttackPowerMax + InOther.AttackPowerMax);
		Result.Reward = (Reward + InOther.Reward);

		return Result;
	}

	MazeEnemy operator-(const MazeEnemy& InOther) const
	{
		MazeEnemy Result;
		Result.Name = "개허접 " + this->Name;	// this : 자기 자신의 주소
		Result.AttackPowerMin = (AttackPowerMin - InOther.AttackPowerMin) / 2;
		if (Result.AttackPowerMin < 1)
		{
			Result.AttackPowerMin = 1;
		}
		Result.AttackPowerMax = (AttackPowerMax - InOther.AttackPowerMax);
		if (Result.AttackPowerMax < 1)
		{
			Result.AttackPowerMax = 1;
		}
		if (Result.AttackPowerMax < Result.AttackPowerMin)
		{
			Result.AttackPowerMax = Result.AttackPowerMin;
		}

		Result.Reward = (Reward - InOther.Reward);

		return Result;
	}

	MazeEnemy operator*(float InOther) const
	{
		MazeEnemy Result;
		Result.Name = "수상한 " + this->Name;
		Result.Health *= InOther;
		Result.AttackPowerMin *= InOther;
		Result.AttackPowerMax *= InOther;
		Result.Reward *= InOther;
		return Result;
	}

	MazeEnemy operator*=(float InOther)
	{
		Name = "거대해진 " + this->Name;
		this->Health *= InOther;
		this->AttackPowerMin *= InOther;
		this->AttackPowerMax *= InOther;
		this->Reward *= InOther;
		return *this;
	}
};