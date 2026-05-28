#pragma once

int main()
{
	// 비트 연산자 : 비트를 계산하는 연산자
	// - 비트 플래그를 사용하기 위해 필요!

	// 비트 And
	//	- &
	//	- 양 변에 있는 데이터의 각 자리수의 비트가 둘 다 1이면 1이다.
	//		ex) 6 & 7 = 0110(2진법)
	//	- 특정 비트에 세팅된 값을 확인하기 위해 사용한다.
	int dataA = 6;
	int dataB = 7;
	printf("dataA & dataB = %d\n", dataA & dataB);

	// 비트 Or
	//	- |
	//	- 양 변에 있는 데이터의 각 자리수의 비트가 하나라도 1이면 1이다.
	//		ex) 6 | 7 = 0111(2진법)
	//	- 특정 비트에 플래그를 세팅할 때 사용한다.
	printf("dataA | dataB = %d\n", dataA | dataB);

	// 비트 Not
	//	- ~
	//	- 비트값이 반전된다.
	unsigned int dataC = 6;
	printf("~dataC = %u\n", ~dataC);

	// 비트 XOR
	//	- ^
	//	- 양 변에 있는 데이터의 각 자리수의 비트가 다르면 1, 같으면 0
	//	- 특정 비트를 토글할 때 사용 (모두 0으로 채우고 토글할 비트만 1로 세팅한 후 XOR 하면 된다.)
	printf("Bit toggle : %d\n", dataA ^ 1);
	printf("Bit toggle : %d\n", (dataA ^ 1) ^ 1);

	// 비트 쉬프트
	//	- <<(왼쪽 쉬프트), >>(오른쪽 쉬프트)
	//	- 왼쪽 쉬프트는 마스크 생성용으로 유용 (곱하기 2로도 사용 가능)
	printf("Bit Left Shift : dataA << 1\n");
	printf("Bit Right Shift : dataA >> 1\n");
	// 1 << 4 : 5번째 비트 세팅

	// enum
	// - 상수의 집합
	enum weekDays	// 별도의 설정이 없으면 첫번째 enum 값은 0이고 1씩 증가
	{
		Mon,
		Tue,
		Wed,
		Thu,
		Fri,
		Sat = 10,	// 따로 설정하면 그 값부터 다시 1씩 증가
		Sun
	};

	int EnumTest1 = Mon;

	enum bitFlagTest	// 비트 플래그용 마스크 설정하는 기본 방식
	{
		Up = 1 << 0,
		Down = 1 << 1,
		Left = 1 << 2,
		Right = 1 >> 3
	};

	int direction = Up | Right;	// 오른쪽 위
	direction = Up | Down | Left | Right;	//모든 방향

	switch (direction)
	{
	case Up:
		break;
	case Down:
		break;
	case Left:
		break;
	case Right:
		break;
	default:
		break;
	}

	// 반복문 : 특정 코드 블록을 조건에 따라 여러번 반복해서 실행할 수 있게 해주는 문(Statement)
	
	// for : 반복 횟수가 명확할 때 사용하기 좋다.
	for (int i = 0; i < 5; i++)	// (변수초기화; 종료조건; 증감부)
	{
		printf("Hello For : %d\n", i);
	}

	// while : 반복 횟수가 명확하지 않고 조건에 따라 반복해야 할 때 사용하기 좋다.
	int j = 0;
	while (j < 5)	// while (true) > 무한루프
	{
		printf("Hello while : %d\n", j);
		j++;
	}
	// do-while : while과 비슷한데 최소 한번은 실행해야 할 때 사용하기 좋다.
	j = 0;
	do
	{
		printf("Hello do-while : %d\n", j);
		j++;
	} while (j < 5);



// 간단 실습 (비트 연산)
// 1. 비트 연산을 활용해 홀짝 판별하기 (입력 데이터는 무조건 양수)
int bitMask = 1;
int targetNumber = 0;
printf("홀짝을 확인할 숫자를 입력하세요 : ");
cin >> targetNumber;
if ((targetNumber & bitMask) != 1)
{
	printf("짝수입니다.\n");
}
else
{
	printf("홀수입니다.\n");
}

// 2. 캐릭터가 사용 가능한 무기 enum 만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드
enum weaponList
{
	Sword	= 1,
	Pistol	= 1 << 1,
	Bow		= 1 << 2,
	Hammer	= 1 << 3,
	Fist	= 1 << 4
};

int playerWeapon = Sword | Hammer | Fist;	// 내 캐릭터는 검, 망치, 주먹을 쓸 수 있다.

printf("다음 중 사용하고 싶은 무기를 선택하세요.\n");
printf("1.검\n2.권총\n3.활\n4.망치\n5.주먹\n");
int selectWeapon = 0;
cin >> selectWeapon;

switch (selectWeapon)
{
case 1 :
	if ((playerWeapon & Sword) != 0)
	{
		printf("검은 사용 가능합니다.\n");
	}
	else
	{
		printf("검은 사용 불가능합니다.\n");
	}
	break;
case 2 :
	if ((playerWeapon & Pistol) != 0)
	{
		printf("권총은 사용 가능합니다.\n");
	}
	else
	{
		printf("권총은 사용 불가능합니다.\n");
	}
	break;
case 3 :
	if ((playerWeapon & Bow) != 0)
	{
		printf("활은 사용 가능합니다.\n");
	}
	else
	{
		printf("활은 사용 불가능합니다.\n");
	}
	break;
case 4 :
	if ((playerWeapon & Hammer) != 0)
	{
		printf("망치는 사용 가능합니다.\n");
	}
	else
	{
		printf("망치는 사용 불가능합니다.\n");
	}
	break;
case 5 :
	if ((playerWeapon & Fist) != 0)
	{
		printf("주먹은 사용 가능합니다.\n");
	}
	else
	{
		printf("주먹은 사용 불가능합니다.\n");
	}
	break;
default :
	break;
}
// playerWeapon & (1 << (selectWeapon - 1)) : 한줄로 가능

// 3. 캐릭터가 사용 가능한 무기를 추가 삭제하기	// 여기는 진짜 모르겠는데?????
std::string WeaponNames[] = { "Sword", "Pistol", "Bow", "Hammer", "Fist" };
std::string WeaponLi = "";
const int numOfWeaponType = 5;
for (int i = 0; i < numOfWeaponType; i++)
{
	if ((playerWeapon & (1 << i)) != 0)
	{
		WeaponLi += WeaponNames[i];
		WeaponLi += " ";
	}
}
printf("플레이어가 사용 가능한 무기는 다음과 같습니다.\n");
printf("[ %s]\n", WeaponLi.c_str());

printf("추가할 무기의 번호를 입력해주세요.\n");
printf("1.Sword 2.Pistol 3.Bow 4.Hammer 5.Fist\n");
int Select = 0;
cin >> Select;



// 간단실습 (반복문)
// 1. 0을 입력받을 때까지 입력받은 숫자의 합을 출력	- while과 do-while 둘 다 해보기
	int inputNumber = 0;
	printf("숫자를 입력하세요 : ");
	cin >> inputNumber;

	int sum = 0;
	while (inputNumber != 0)
	{
		sum += inputNumber;
		printf("더할 숫자를 입력하세요 : ");
		cin >> inputNumber;
	}
	printf("입력된 값들의 합은 %d 입니다.\n", sum);

	do
	{
		printf("더할 숫자를 입력하세요 : ");
		cin >> inputNumber;
		sum += inputNumber;
	} while (inputNumber != 0);
	printf("입력된 값들의 합은 %d 입니다.\n", sum);


	// 2. 입력받은 수의 구구단 출력하기
	int inputNumber = 0;
	printf("출력할 구구단 단수를 입력하세요 : ");
	cin >> inputNumber;
	printf("%d 단을 출렵합니다.\n", inputNumber);
	for (int i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", inputNumber, i, inputNumber * i);
	}


	// 3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기
	int inputNumber = 0;
	printf("마지막 수를 입력하세요 : ");
	cin >> inputNumber;
	for (int i = 1; i <= inputNumber; i++)
	{
		if (i % 2 == 0)	// 짝수면 아래쪽 코드 스킵하기
		{
			continue;	// 반복문에서 이번 반복만 스킵하는 것
		}

		if (i % 2 == 1)
		{
			printf("%d는 홀수입니다.\n", i);
		}
	}


	// 4. 1~100 중에 7의 배수만 출력하기
	for (int i = 1; i < 101; 1++)
	{
		if (i % 7 == 0)
		{
			printf("%d는 7의 배수입니다.\n", i);
		}
	}


	// 5. 팩토리얼 계산하기
	int inputNumber = 0;
	printf("팩토리얼을 계산할 수를 입력하세요 : ");
	cin >> inputNumber;
	int sum = 1;
	for (int i = 2; i <= inputNumber; i++)
	{
		sum *= i;
	}
	printf("결과값은 %d입니다.\n", sum);


	// 6. *로 피라미드 모양의 삼각형 찍기
	int inputNumber = 0;
	printf("만들고자 하는 피라미드의 층수를 입력하세요 : ");
	cin >> inputNumber;
	for (int i = 0; i < inputNumber; i++)	// 한번 반복될 때마다 한층씩 그리기 위한 반복문(for)
	{
		for (int j = 0; j < inputNumber - 1 - i; j++)
		{
			prinf(" ");
		}

		for (int j = 0l j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}



	// 랜덤
	srand(time(0));		// !랜덤의 시드값을 현재 시간으로 설정하기! (프로그램 실행할 때 한번만 하면 됨)

	int RandomNumber;
	int TestCount = 10000000;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
	for (int i = 0; i < TestCount; i++)
	{
		RandomNumber = rand() % 6 + 1;	// 1~6이 랜덤으로 골라지게 됨	// rand() - 0에서 RandMax 사이에서 랜덤하게 나옴
		//printf("Random : %d\n", RandomNumber);
		switch (RandomNumber)
		{
		case 1:
			num1++;
			break;
		case 2:
			num2++;
			break;
		case 3:
			num3++;
			break;
		case 4:
			num4++;
			break;
		case 5:
			num5++;
			break;
		case 6:
			num6++;
			break;
		default:
			printf("ERROR!! ERROR!! ERROR!!\n");
			break;
		}
	}
	printf("num1: [%d]\tnum2: [%d]\tnum3: [%d]\tnum4: [%d]\tnum5: [%d]\tnum6: [%d]", num1, num2, num3, num4, num5, num6);
