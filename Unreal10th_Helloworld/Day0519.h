#pragma once

// 이진수
// - 0과 1로만 표현되는 숫자
//      ex) int i = 8;  메모리 : 0000 0000 0000 0000 0000 0000 0000 1000
//          6.75 > 6 = 0110
//               > 0.75 > 소수 자리가 될 때까지 2를 곱하고 정수 부분을 소수점 뒤로 > 1.5 > 1.0
//               > 0110.11
// - 정규화 과정
//      1.1011 * 2(-2)
//      부호 비트 / 지수부 / 가수부를 8비트로

//  float(부동소수점)
//  - 32비트
//  - 소수점이 있는 숫자를 저장
//  - 구조적으로 오차가 있는 데이터 타입 > 같다는 비교를 조심해서 해야 함
//  - 숫자 뒤에 f를 붙여야 함

// double(부동소수점)
//  - 64비트

float RealNumber = 0.0f;    // 0.0f는 float
//RealNumber = 0.1;           // 0.1은 double > 암시적 변환이 일어나 float로 저장됨 > 워닝 발생
RealNumber = (float)0.1;    // 명시적 변환(Casting)

printf("이것은 실수입니다 : %f\n", RealNumber);

RealNumber = 0.1f + 0.5f;
printf("이것은 실수입니다 : %.2f\n", RealNumber);     // 소수점 2번째 자리까지 출력
RealNumber = 0.2f;
printf("이것은 실수입니다 : %8.2f\n", RealNumber);    // 소수점 포함 전체 8자리, 소수점 아래 2번째 자리까지 출력
printf("float타입의 사이즈는 [%d]byte입니다.\n", (int)sizeof(float));

// bool(불리언 타입)
// - true, false 둘만 저장하는 데이터
// - 프로그램의 각종 분기를 결정할 때 사용
// - 8bit

bool bTest = false;
bTest = true;
printf("bool타입의 사이즈는 [%d]byte입니다.\n\n", (int)sizeof(bool));

// char(캐릭터 타입)
// - 글자 하나를 저장하는 데이터 타입
// - 8bit짜리 정수형 데이터 타입(아스키코드)

char TestCharacter = 'a';
TestCharacter = 'b';
TestCharacter = 'B';
printf("char c = %c\n", TestCharacter);

// 문자열
// - char*, std::string
std::string TestString = "Hello World!\n";

// 부호 없는 인티저 (똑같이 32bit, 범위 0~42억)
unsigned int TestInteger = 0;
// 64bit 인티저
long long TestInteger64 = 0;
unsigned long long TestInteger64_2 = 0;

// 유니코드 캐릭터
wchar_t UnicodeChar = L'가';

int Size = 100;
printf("한 변이 %d인 정사각형의 넓이는 %d입니다.\n", Size, Size* Size);
Size = 50000;
printf("한 변이 %d인 정사각형의 넓이는 %ud입니다.\n\n\n", Size, (unsigned)Size* (unsigned)Size);

// 상수
// - 절대 변하지 않는 숫자
// - 코드의 안정성과 가독성을 높여준다
const int TestConst = 10;

// 간단 실습
// 1. 원의 반지름 입력받고 넓이 구하기
// 2. 3개의 값을 입력받고 평균값 구하기
// 3. 정가와 할인율 입력받고 할인된 가격 구하기

float radius = 0.0f;
printf("원의 반지름을 입력하시오 : ");
cin >> radius;
printf("원의 넓이는 [%.2f] 입니다.\n\n", radius* radius * 3.141592f);

float num1 = 0.0f; float num2 = 0.0f; float num3 = 0.0f;
printf("숫자 3개를 입력하시오 : ");
cin >> num1 >> num2 >> num3;
float average = 0.0f;
average = (num1 + num2 + num3) / 3;
printf("세 값의 평균은 [%.1f]입니다.\n\n", average);

float price = 0.0f;
float discount = 0.0f;
float dis = discount / 100;
printf("상품의 가격을 입력하시오 : ");
cin >> price;
printf("상품의 할인율(퍼센트)을 입력하시오 : ");
cin >> discount;
float finalPrice = price - (price * discount * 0.01f);
printf("상품의 구매가는 [%.0f]원입니다\n", finalPrice);


// 비교 연산자
// - 두 변수를 비교하는 연산자 (크다, 작다, 같다 등을 계산)
bool bTest = false; // false가 디폴트, 특정 경우에 true
bTest = 10 > 5;     // true
bTest = 10 < 5;     // false
bTest = 10 >= 5;    // true
bTest = 10 >= 10;   // true
bTest = 10 > 10;    // false
bTest = 10 == 10;   // true     // == : 양변의 값이 같은지 확인하는 비교연산자

bTest = 0.1f + 0.2f == 0.3f;    // 이런식의 비교는 절대 금지


// 조건문
// - 특정 조건에 따라 다른 동작을 하게 만드는 문(statement)

// if
int a = 10;
int b = 20;
if (a > b)
{
    printf("a가 b보다 큽니다.\n");
}

// if else
// - () 사이의 조건식이 true면 아래의 {} 코드를 실행하고 false면 else 아래의 {} 코드를 실행한다.
if (a > b)
{
    printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
}
else
{
    printf("a(%d)가 b(%d)보다 작습니다.\n", a, b);
}

// else if
// - if를 중첩하기 (분기가 나눠짐)
if (a > (b * 2))
{
}
else if (a > b)
{
}
else if (a > (b / 2))
{
}

// switch
// - 값이 여러 가지 중 하나일 때 각각의 경우에 따라 다르게 처리할 때 사용
a = 654;
switch (a)
{
case 1:
    printf("a는 1입니다.\n");
    break;  // break는 괄호를 벗어나는 코드
case 10:
    printf("a는 10입니다.\n");
    break;
default:
    printf("a는 %d입니다.\n", a);
    break;
}

// 삼항 연산자
int x = (a > 10) ? 1 : 0;   // ? 앞의 조건식이 참이면 ?와 : 사이에 있는 값, 거짓이면 : 뒤에 있는 값이 x.

// 논리 연산자
// - 참 아니면 거짓이 나오는 연산 
// - bool을 다루는 연산자

// &&   :   And.
//          && 연산자 좌우의 값이 모두 true면 true, 아니면 false.
//          bool bTest = true && true;  > 이때만 bTest가 true
// ||   :   Or.
//          || 연산자 좌우의 갑이 하나라도 true면 true. 둘 다 false일 때만 false.
//          bool bTest = false || false; > 이때만 bTest가 false
// !    :   Not
//          true는 false로 만들고, false는 true로 변경.
//          bool bTest = true;  bTest = !bTest; > bTest는 false

int Point = 78;
if ((Point < 90) && (Point >= 80))
{
    printf("B학점입니다.\n");
}

// 조건문 간단 실습 (입력은 정수만)
// 1. 숫자를 입력받아 양수인지 음수인지 0인지 판단하는 코드
// 2. 숫자를 입력받아 홀수인지 짝수인지 판단하는 코드
// 3. 두 수를 입력받아 더 큰수를 출력하는 코드. 같을 경우 같다고 출력.

// 논리연산자 간단 실습
// 1. 나이와 키를 입력받아 [6세 이상 120cm 이상]일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기
// 2. 점수를 입력받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기
// 3. 세 과목의 점수를 입력받아 세 과목 평균 60점 이상이면 합격, 아니면 불합격을 출력하는 프로그램을 작성하기
//	  한 과목이라도 40점 미만이면 불합격 출력

// 테스트는 경계값과 중간값을 꼭 체크해야 한다.

int num1 = 0;
printf("숫자를 입력하시오 : ");
cin >> num1;
if (num1 > 0)
{
	printf("양수입니다.\n");
}
else if (num1 == 0)
{
	printf("0입니다.\n");
}
else if (num1 < 0)
{
	printf("음수입니다.\n");
}

printf("\n");

int num2 = 0;
printf("숫자를 입력하시오 : ");
cin >> num2;
if (num2 % 2 == 0)
{
	printf("짝수입니다.\n");
}
else
{
	printf("홀수입니다.\n");
}

printf("\n");

int num3 = 0, num4 = 0;
printf("숫자 2개를 입력하시오 : ");
cin >> num3 >> num4;
if (num3 > num4)
{
	printf("더 큰 수는 %d 입니다.\n", num3);
}
else if (num3 < num4)
{
	printf("더 큰 수는 %d 입니다\n", num4);
}
else if (num3 == num4)
{
	printf("두 숫자의 크기는 같습니다.\n\n");
}

printf("\n");

const int baseAge = 6;			// 변하지 않는 기준점을 설정할 때
const int baseHeight = 120;		// 기준점 변경시 하나만 변경해도 됨
int age = 0;
int height = 0;
printf("나이와 키(cm)를 입력하세요 : ");
cin >> age >> height;
if (age >= baseAge && height >= baseHeight)
{
	printf("롤러코스터 탑승 [가능]\n");
}
else
{
	printf("롤러코스터 탑승 [불가능]\n");
}

printf("\n");

const int gradeA = 90;
const int gradeB = 80;
const int gradeC = 70;
const int gradeD = 60;
int point = 0;
printf("시험 점수를 입력하세요 : ");
cin >> point;
if (point >= gradeA)
{
	printf("A학점입니다.\n");
}
else if (point >= gradeB)
{
	printf("B학점입니다.\n");
}
else if (point >= gradeC)
{
	printf("C학점입니다.\n");
}
else if (point >= gradeD)
{
	printf("D학점입니다.\n");
}
else
{
	printf("F학점입니다.\n");
}

printf("\n");

int point1 = 0, point2 = 0, point3 = 0;
printf("세 과목의 점수를 각각 입력하세요 : ");
cin >> point1 >> point2 >> point3;
printf("입력된 점수는 다음과 같습니다.\n[%d], [%d], {%d]", point1, point2, point3);
if ((point1 + point2 + point3) / 3 >= 60 && point1 >= 40 && point2 >= 40 && point3 >= 40)
{
	printf("합격입니다.\n");
}
else
{
	printf("불합격입니다.\n");
}
// if (point1 < 40 || point2 < 40 || point < 40) 을 불합격 처리하고 그 다음 분기를 평균 60 이상이냐 아니냐로 나누어도 됨
// 평균값에 오차 0.0001f을 더해서 해주면 좋음


	// 1. 세 수 중 최댓값과 최솟값 찾기
	//		- 3개의 정수를 입력받아, 그중 가장 큰 수와 가장 작은 수를 출력
	// 2. 세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기
	//		- 조건 : 삼각형이 되려면 '한 변의 길이 < 나머지 두 변의 길이의 합'이어야 함.
	// 3. 미니 계산기
	//		- 두 개의 정수와 하나의 연산자(+, -, *, / )를 입력받아 결과를 출력
	//		- 단, 나눗셈에서 0으로 나누려고 하면 "0으로 나눌 수 없습니다"라는 에러 메시지를 출력
	// 4. 윤년 판별기
	//		- 연도(예 : 2024)를 입력받아 그 해가 윤년인지 평년인지 출력
	//		- 윤년의 조건 :
	//			연도가 4로 나누어 떨어지면 윤년이다.
	//			하지만 100으로 나누어 떨어지면 평년이다.
	//			그럼에도 400으로 나누어 떨어지면 윤년이다.

printf("1. 최댓값/최솟값 찾기\n");
int num1 = 0, num2 = 0, num3 = 0;
printf("세 가지 숫자를 입력하세요 : ");
cin >> num1 >> num2 >> num3;
if (num1 >= num2 && num1 >= num3)
{
	printf("최댓값은 [%d] 입니다.\n", num1);
	if (num2 < num3)
	{
		printf("최솟값은 [%d] 입니다.\n", num2);
	}
	else
	{
		printf("최솟값은 [%d] 입니다.\n", num3);
	}
}
else if (num2 >= num1 && num2 >= num3)
{
	printf("최댓값은 [%d] 입니다.\n", num2);
	if (num1 < num3)
	{
		printf("최솟값은 [%d] 입니다.\n", num1);
	}
	else
	{
		printf("최솟값은 [%d] 입니다.\n", num3);
	}
}
else if (num3 >= num1 && num3 >= num2)
{
	printf("최댓값은 [%d] 입니다.\n", num3);
	if (num1 < num2)
	{
		printf("최솟값은 [%d] 입니다.\n", num1);
	}
	else
	{
		printf("최솟값은 [%d] 입니다.\n", num2);
	}
}

printf("\n\n");

printf("2. 삼각형 조건 판별\n");
int line1 = 0, line2 = 0, line3 = 0;
printf("세 개의 선분 길이를 입력하세요(cm) : ");
cin >> line1 >> line2 >> line3;
if (line1 + line2 > line3 && line1 + line3 > line2 && line2 + line3 > line1)
{
	printf("이 선분들로 삼각형을 만들 수 있습니다.\n");
}
else
{
	printf("이 선분들로는 삼각형을 만들 수 없습니다.\n");
}

printf("\n\n");

printf("3. 미니계산기\n");
int numA = 0, numB = 0;
char oper = 0;
float Result = 0.0f;
printf("두 개의 정수를 입력하세요 : ");
cin >> numA >> numB;
printf("+, - , * , / 중 사용할 연산자를 입력하세요 : ");
cin >> oper;
switch (oper)
{
case '+':
	Result = numA + numB;
	break;
case '-':
	Result = numA - numB;
	break;
case '*':
	Result = numA * numB;
	break;
case '/':
	if (numB != 0)
	{
		Result = numA / numB;
	}
	else
	{
		printf("0으로 나눌 수 없습니다.\n");
	}
	break;
default:
	break;
}
if (oper != '/')
{
	printf("%d %c %d\n", numA, oper, numB);
	printf("연산의 결과값은 [%.2f] 입니다.\n", Result);
}
else
{
	if (numB != 0)
	{
		printf("%d %c %d\n", numA, oper, numB);
		printf("연산의 결과값은 [%.2f] 입니다.\n", Result);
	}
}


printf("\n\n");

printf("4. 윤년 판별기\n");
int year = 0;
printf("윤년인지 판별할 연도를 입력하세요 : ");
cin >> year;
int yearF = year % 4;
int yearH = year % 100;
int year4H = year % 400;
bool bLeap = ((yearF == 0 && yearH != 0) || year4H == 0);
if (bLeap)
{
	printf("%d년은 윤년입니다.\n", year);
}
else
{
	printf("%d년은 평년입니다.\n", year);
}