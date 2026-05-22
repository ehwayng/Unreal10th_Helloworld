#include <iostream>
#include "Day0522.h"

void Day0522_Array()
{
	// 배열
	// 같은 종류의 데이터 타입을 한번에 여러 개 저장할 때 사용
	// 같은 데이터 타입을 가진 요소들이 "연속적"으로 저장되어있는 데이터 구조
	// 빠르게 각 요소에 접근이 가능 (랜덤 엑세스 성능이 매우 뛰어남)
	// 단점 : 크기가 고정. 삽입/삭제가 힘들다.

	int Num1 = 0, Num2 = 0, Num3 = 0;	// 이전까지 데이터 3개 저장하는 방식
	int Numbers[3];			// 배열을 이용해 데이터 3개 저장
	Numbers[0] = 10;		// 배열의 각 요소에 접근하는 방식
	Numbers[1] = 20;
	Numbers[2] = 30;

	Numbers[1] = Numbers[0];	// Numbers의 첫번째 요소를 두번째 요소에 대입하기

	// Numbers[3] = 100;			// 범위를 벗어나서 접근하는 것은 안됨!

	int Array1[5] = { 1, 4, 76, 32, 6 };	// 순서대로 데이터 초기화
	int Array2[5] = { 32, 6 };				// 32, 6 들어가고 나머지는 0

	int ArraySize = sizeof(Array1);			// int의 사이즈(4)x5(개)
	printf("ArraySize : %d Byte\n", ArraySize);
	int ArrayCount = ArraySize / sizeof(int);
	printf("ArrayCount : %d 개\n\n", ArrayCount);

	// 2차원 배열
	int Array3[4][3];		// int 3개짜리 배열이 4개 있다는 의미
	int Array4[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };		// int Array4[12];와 메모리상 구조는 동일
}

// 간단실습

void Day0522_Array_Example01()
{
	// 1. 배열 만들고 초기화하고 전부 출력해보기 (1차원과 2차원 모두)
	int Array1[5] = { 2, 3, 5, 7, 11 };
	int Array1Size = sizeof(Array1) / sizeof(Array1[0]);
	printf("Array1 = [ ");
	for (int i = 0; i < Array1Size; i++)
	{
		printf("%d ", Array1[i]);
	}
	printf("]\n");

	const int Array2Size = 5;	// constexpr이 더 정확하다.
	int Array2[Array2Size] = { 0, };
	printf("Array2 = [ ");
	for (int i = 0; i < Array2Size; i++)
	{
		printf("%d ", Array2[i]);
	}
	printf("]\n");

	int Array3[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	printf("Array3 = [ \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", Array3[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void Day0522_Array_Example02()
{
	printf("\n");
	// 2. 배열 내부 값을 모두 더하고 평균 구해보기
	const int Size = 5;
	int Array[Size] = { 2, 3, 5, 7, 11 };
	int Sum = 0;
	printf("Array = { ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", Array[i]);
		Sum += Array[i];
	}
	float Average = Sum / (float)Size;	// integer 나누기 integer는 integer밖에 안 되기 때문에 보통 나누는 값을 float로 변환하면 결과도 float으로 저장된다.
	printf("}\n");
	printf("Sum = %d, Average = %.1f\n", Sum, Average);
}

void Day0522_Array_Example03()
{
	printf("\n");
	// 3. 배열의 값 중 최대값과 최소값 구해보기
	int Max = INT32_MIN;
	int Min = INT32_MAX;


	int Array[5] = { 0, -55, 99, 10, 53 };
	const int ArraySize = 5;	// constexpr이 더 정확하다.
	printf("Array = [ ");
	for (int i = 0; i < ArraySize; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");

	for (int i = 0; i < 5; i++)
	{
		if (Max < Array[i])
		{
			Max = Array[i];
		}
		if (Min > Array[i])
		{
			Min = Array[i];
		}
	}
	printf("Max = %d, Min = %d\n", Max, Min);
}


void Day0522_Casting()
{
	// Casting
	// 값의 데이터 타입을 다른 타입으로 변경하는 것
	
	// C 스타일 - 강제 변환(위험함, 안되는 것도 해버림)
	int Integer = 10;
	float RealNumber = (float)Integer;	// Integer에 있는 값을 float 타입으로 임시 변경한 후 RealNumber에 저장

	bool Boolean = (bool)Integer;
	Boolean = (bool)0;

	int i = 0;

	// C++ 스타일 
	// 1. static_cast
	//		- C 스타일 cast와 매우 유사
	//		- 문법적으로 암시적 변환이 허용될 때만 캐스팅을 한다.
	RealNumber = static_cast<float>(Integer);
	// 2. dynamic_cast
	//		- 상속을 배워야 의미가 있다. 다운캐스팅을 할 때 사용.
	//		- 캐스팅 할 수 있으면 null이 아닌 값. 할 수 없으면 null을 반환.
	//		- RTTI(RunTime Type Information)를 관리
	//		- 변환 속도가 매우 늦다. (일반적인 게임에서 남용하면 안됨!)
	// 캐스팅된 결과를 받을 변수 = dynamic_cast<캐스팅할 타입>(변수);
	// 3. const_cast
	//		- const나 volatile 속성을 제거하거나 추가할 때 사용.
	//		- 사용되지 않는 것이 권장(레거시 처리용)
	// 4. reinterpret_cast
	//		- C 스타일 캐스트의 위험한 부분을 그대로 가져온 것
	//		- 원래 타입의 구조를 무시하고 새 타입으로 강제적으로 해석하게 하는 cast
	//		- 포인터 타입간 변환이나 유니온 변환 같은 경우 사용
}

void Day0522_Reference()
{
	// 참조
	//	- 변수의 별명
	//	- 참조 대상 재설정 불가능 (선언할 때 참조할 변수를 지정해줘야 한다.)
	//	- 참조를 변경하면 참조하고 있는 변수인
			
	int Num = 10;
	int Target = Num;
	Target = 15;

	Test_Reference1(Num);
	Num = Test_Reference2(Num);

	int& NumRef = Num;
	int i = 0;
	// int& Ref;	// 참조할 변수 지정없이 사용하는 건 안된다.
	NumRef = 100;	// 참조하고 있는 변수인 Num도 100이 된다.

	int Num1 = 0, Num2 = 0, Num3 = 0;
	Test_Reference3(Num1, Num2, Num3);
}

void Test_Reference1(int Data)
{
	Data += 10;
}

int Test_Reference2(int Data)
{
	return Data += 10;
}

void Test_Reference3(int& OutData1, int& OutData2, int& OutData3)
{
	OutData1 = 10;
	OutData2 = 20;
	OutData3 = 30;
}


void Day0522_ArrayParameter()
{
	const int Length = 5;
	int Array[Length] = { 10, 50, 30, 20, 40 };

	// 포인터(*)와 배열은 근본적으로 같다.
	Test_ArrayParameter(Array, Length);
}

void Test_ArrayParameter(int* Array, int Length)
{
	printf("Array : [ ");
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}


void Day0522_Shuffle()
{
	const int DataSize = 100;
	int Data[DataSize] = {0, };

	for (int i = 0; i < DataSize; i++)
	{
		Data[i] = i;
	}
	Test_ArrayParameter(Data, DataSize);

	FisherYatesShuffle(Data, DataSize);
	Test_ArrayParameter(Data, DataSize);
}

void FisherYatesShuffle(int* Array, int Length)		// 피셔 예이츠 알고리즘 : 많이 쓰는 셔플법
{
	// 1. 인덱스는 배열의 마지막 요소에서 첫번째 요소로 진행
	// 2. 인덱스가 가리키는 요소와 0 ~ 인덱스 중 임의의 요소를 선택
	// 3. 인덱스가 가리키는 요소와 임의로 선택된 요소를 교환
	// 4. 인덱스는 1 감소
	
	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];	// 값이 바뀌기 전 i의 값을 잃지 않기 위해 임시 저장
		Array[i] = Array[j];
		Array[j] = Temp;
	}

}

// 5/22 실습

// 1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅 (배열 활용)
void Day0522_Practice1()
{
	printf("1. 주사위 100만번 던지기\n");
	int Dice[6] = { 0, };		// 각 요소가 횟수 (첫번째가 1의 눈이 나온 횟수)
	for (int i = 0; i <1000000; i++)
	{
		int CurrentDice = (rand() % 6) + 1;
		Dice[CurrentDice - 1] += 1;
	}

	int Sum = 0;
	printf("Array = { ");
	for (int j = 0; j < 6; j++)
	{
		printf("%d ", Dice[j]);
		Sum += Dice[j];
	}
	printf("}\n");

	printf("주사위를 굴린 횟수 : 총 %d 회\n", Sum);
	printf("각 눈의 수가 나온 횟수\n");
	printf("[1의 눈] %d회\n[2의 눈] %d회\n[3의 눈] %d회\n[4의 눈] %d회\n[5의 눈] %d회\n[6의 눈] %d회\n",
		Dice[0], Dice[1], Dice[2], Dice[3], Dice[4], Dice[5]);
}

// 2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기 (파라메터 : int* Array, int Size)
void Day0522_Practice2()
{
	printf("2. 배열 뒤집기\n");
	const int Size = 5;
	int Array[Size] = { 2, 3, 7, 11, 13 };

	Test_ArrayParameter(Array, Size);

	printf("Flip 하겠습니다.\n");

	FlipArray(Array, Size);
	Test_ArrayParameter(Array, Size);
}

void FlipArray(int* Array, int Size)
{
	for (int i = 0; i < (Size / 2); i++)
	{
		int Save = Array[i];
		Array[i] = Array[Size - (i + 1)];
		Array[Size - (i + 1)] = Save;
	}
}

// 3. 로또 번호 생성기 (셔플알고리즘 활용)
//  	- 전체 숫자 범위 : 1 ~ 45
//  	- 맞춰야 하는 숫자 개수 : 6개
void Day0522_Practice3()
{
	printf("3. 로또 번호 생성기\n");
	const int Size = 6;
	int Lotto[6] = { 0, };
	for (int i = 0; i < 6; i++)
	{
		Lotto[i] = rand() % 45 + 1;
	}
	printf("6개의 숫자를 추첨했습니다.\n");
	Test_ArrayParameter(Lotto, Size);
	printf("순서를 섞어 최종 당첨번호를 공개합니다.\n");
	FisherYatesShuffle(Lotto, Size);
	Test_ArrayParameter(Lotto, Size);
}

// 4. 미로 탈출 게임 만들기
//  	- 2차원 배열을 활용하여 텍스트 기반 미로탈출게임 구현
void Day0522_Practice4()
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
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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
	enum PlayerMove
	{
		
	};



}





