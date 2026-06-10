#pragma once
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <set>
#include "T_FixedStack.h"

class Day0610
{
public:
	void TestMain();

	void TestTemplateClass();
	void TestTree();

	void TestSet();
	void PrintSet(const std::set<int>& InTarget);

	void TestMap();

	void Practice0610();
};

// 간단실습
// 1. 템플릿을 이용한 계산기 클래스 만들기
//    - Add, Sub, Multiple, Divid
//	  - int * int , float * int , int * float , float * float 모두 가능해야 함
// 2. BitFlag용 비트 연산자 추가하기
//	  - & , |= , &=


//템플릿 클래스 예시
template <typename T>
struct Coordinate
{
	T x;
	T y;

	Coordinate() : x{}, y{}
	{
	};
	Coordinate(T InX, T InY)
		:x(InX), y(InY)
	{
	}

	void Print() const
	{
		/* if constexpr : 컴파일 타임에 조건이 true면 코드를 생성하고 아니면 생성하지 않는다. */
		if constexpr (std::is_same_v<T, int>)
		{
			//T타입이 int라면 true를 리턴 (이 영역의 코드 사용)
			printf("(%d, %d)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, float>)
		{
			//T타입이 float라면 true를 리턴 (이 영역의 코드 사용)
		}
	}
};

class Calculator
{
public:
	/* 덧셈 */
	template <typename T1, typename T2>
	auto Add(T1 a, T2 b) const
	{
		return a + b;	//C++이 자동으로 더 큰 타입으로 변환하여 반환
	}

	/* 뺄셈 */
	template <typename T1, typename T2>
	auto Sub(T1 a, T2 b) const
	{
		return a - b;
	}

	/* 곱셈 */
	template <typename T1, typename T2>
	auto Multi(T1 a, T2 b) const
	{
		return a * b;
	}

	/* 나눗셈 */
	template <typename T1, typename T2>
	auto Div(T1 a, T2 b) const
	{
		if (b == 0)
			throw std::runtime_error("0으로 나눌 수 없습니다.\n");
		return a / b;
	}
};

struct SetTestData
{
	int a = 0;
	float b = 0;

	SetTestData() = default;
	SetTestData(int InA, float InB) : a(InA), b(InB) {};

	bool operator<(const SetTestData& InOther) const
	{
		return a < InOther.a;
	}
};

struct SetTestDataFail
{
	int a = 0;
	float b = 0;

	SetTestDataFail() = default;
	SetTestDataFail(int InA, float InB) : a(InA), b(InB) {};
};

struct SetTestDataFunctor
{
	int a = 0;
	float b = 0;

	SetTestDataFunctor() = default;
	SetTestDataFunctor(int InA, float InB) : a(InA), b(InB) {};
};

struct ComepareTest
{
	bool operator()(const SetTestDataFunctor& InLeft, const SetTestDataFunctor& InRight) const
	{
		return InLeft.a < InRight.a;
	}
};

enum class CharacterType
{
	Warrior,
	Mage,
	Cheif
};

struct CharacterData
{
	int Level;
	int HP;
	int Exp;
};