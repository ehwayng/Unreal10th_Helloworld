#pragma once


//int Number = 10;    // 대입 연산자로 Number에 10을 넣었다.
//printf("Number : %d\n", Number);
//printf("Number : %5d\n", Number);   // Number를 정수 5자리로 출력하라
//Number = 20;        // 대입 연산자로 Number에 20을 넣었다. (덮어써짐)
//printf("Number : %d\n", Number);
//Number = 5 + 10;    // 산술 연산자 +를 이용해서 5와 10을 더 하고 그 결과를 Number에 대입한다. (순서 : 오른쪽 항부터)
//printf("Number : %d\n", Number);
//Number = 7 % 3;      // 산술 연산자 %를 이용해서 7을 3으로 나눈 나머지를 구하고(1), 그 결과를 Number에 대입한다.
//printf("Number : %d\n", Number);

//int Temp1 = 7;

//Number += Temp1;    // Number와 Temp1의 값을 더하고 그 결과를 Number에 덮어쓴다. (Number = 8)
//printf("Number : %d\n", Number);
//Number *= Temp1;    // Number와 Temp1의 값을 곱하고 그 결과를 Number에 덮어쓴다. (Number = 56)
//printf("Number : %d\n", Number);

//Number--;   // (Number = 55)
//Number--;   // (Number = 54)
//Number--;   // (Number = 53)
//printf("Number : %d\n", Number);


//printf("Hello World!\n");
   //int number = 0;
   ////int size = scanf("%d",&number);   // C 스타일의 표준 입력 방식 (위험하다)
   //std::cin >> number; // C++ 스타일의 표준 입력 방식
   //printf("Input number is %d", number);

//printf("나이를 입력하세요 : ");
//int Age = 0;    // Age라는 int 변수를 선언했다.
//std::cin >> Age;
//printf("당신의 나이는 [%d]살입니다.\n", Age);

//  변수(Variable)
//  - 변하는 숫자
//  - 컴퓨터에 값을 기억시키기 위해 만들고 사용
//  - 메모리의 일정 공간을 확보하고 이름을 붙여 사용하는 것
//      ex) 데이터타입 변수명; int age;

//  int(인티저, Integer)
//  - 정수형 타입 (*정수: 소수점이 없는 숫자)
//  - 일반적으로 32bit의 크기를 가진다. (범위 약 -21억 ~ 21억)

//  변수 네이밍 규약(중요!)
//  - 알아보기 쉽고, 간결해야 한다. (길어지더라도 알아보기 좋은 것 권장)
//  - 수업 중에는 언리얼 코딩 규약을 따를 것 (파스칼 케이스 기반 + 약간의 변형)
//  - 문법적 금지
//      *예약어(컴파일러가 미리 사용하려고 잡아 놓은 이름     ex) int float
//      *숫자로 시작하기
//      *대부분의 특수문자(언더바_는 가능. 하지만 비권장)
//      *띄어쓰기
//  - 비권장
//      *영어가 아닌 문자
//      *알파벳은 같지만 대소문자가 다른 두 변수

    //  연산자(Operator)
    //  - 산술 연산자 : + - * / %(나머지)
    //      > 사칙연산처럼 숫자끼리 더하거나 빼거나 하는 것들
    //  - 대입 연산자 : =
    //      > '='의 오른쪽에 있는 값을 '=' 왼쪽에 있는 변수에 넣어라
    //      ex) int i = 20; > i라는 변수에 20이라는 값을 넣으라는 의미
    // 
    //  - 복합 대입 연산자
    //      > 줄여 쓰기용. 대입 연산자와 다른 연산자를 합쳐서 복합적으로 사용하는 연산자.
    //      ex) int a, int b;
    //          a = a + b; >> a += b;       // 둘 다 같은 코드
    //  - 증감 연산자
    //      > 줄여 쓰기용. 정수에 1을 더하거나 뺄 때 사용하는 연산자.
    //      ex) a = a + 1; >> a++;      // 둘 다 같은 코드  
    //          b = b - 1; >> b--;

//간단실습
//  두 수를 입력받아 스왑하기


[실습 내용]


#include <iostream>

int main()
{
    int Num1 = 0, Num2 = 0, Num3 = 0;
    printf("첫번째 숫자를 입력하세요 : ");
    cin >> Num1;    //std::cin >> Num1;
    printf("두번째 숫자를 입력하세요 : ");
    cin >> Num2;
    printf("입력한 숫자는 %d, %d 입니다.\n", Num1, Num2);
    Num3 = Num1;
    Num1 = Num2;
    Num2 = Num3;
    printf("스왑한 결과는 %d, %d 입니다.\n", Num1, Num2);
}


#include <iostream>
using namespace std;

int main()
{
    printf("1. 온도 변환기\n");
    int Number = 0;	// 현재온도(섭씨)
    printf("현재 온도(섭씨)를 입력하세요 : ", Number);
    cin >> Number;
    int Temp1 = 9;
    int Temp2 = 5;
    int Temp3 = 32;
    Number *= Temp1;
    Number /= Temp2;
    Number += Temp3;
    printf("화씨 : %d도\n", Number);
    printf("\n");

    printf("2. 시간 계산기\n");
    Number = 0; //초시간
    printf("변환할 시간을 입력하세요 : ", Number);
    cin >> Number;
    int Time1 = Number / 3600;
    int Time2 = Number % 3600 / 60;
    int Time3 = Number % 3600 % 60;
    printf("변환 완료 : %d시간 %d분 %d초\n", Time1, Time2, Time3);
    printf("\n");

    printf("3. 동전 갯수 계산\n");
    Number = 0; //총금액
    printf("금액 입력 : ", Number);
    cin >> Number;
    int mon1 = Number / 500;
    int mon2 = Number % 500 / 100;
    int mon3 = Number % 500 % 100 / 50;
    int mon4 = Number % 500 % 100 % 50 / 10;
    printf("결과 : 500원 %d개, 100원 %d개, 50원 %d개, 10원 %d개\n", mon1, mon2, mon3, mon4);
    printf("\n");

    printf("4. 자리수 분리\n");
    Number = 0;   //입력 숫자
    printf("입력 숫자(세자리) : ", Number);
    cin >> Number;
    int hun = Number / 100;
    int ten = (Number - 100 * hun) / 10;
    int one = (Number - 100 * hun - 10 * ten);
    printf("100의 자리 : %d, 10의 자리 : %d, 1의 자리 : %d\n", hun, ten, one);
    int sum = hun + ten + one;
    printf("각 자리수의 합 : %d\n", sum);
    printf("\n");

    printf("5. 파일 용량 환산기\n");
    Number = 0;    //메가바이트
    printf("변환하기(MB) : ", Number);
    cin >> Number;
    int kb = Number * 1024;
    int byte = Number * 1024 * 1024;
    printf("결과 : %d KB / %d Byte\n", kb, byte);
    printf("\n");

    printf("6. 타일 개수 계산기\n");
    int wid = 0; int hei = 0;
    int tile = 30;
    printf("방의 가로, 세로 길이를 순서대로 입력하세요(cm) : ");
    cin >> wid >> hei;
    int widCount = (wid + (tile - 1)) / tile;
    int heiCount = (hei + (tile - 1)) / tile;
    printf("방을 채우기 위해 필요한 타일 : %d개\n", widCount * heiCount);

    printf("----------------------------------------");

    printf("\n\n\n");
    printf("<나의 저축 도우미!>\n");
    int money = 0;
    printf("목표 금액 : ");
    cin >> money;
    int per = 0;
    printf("목표 기간 : ");
    cin >> per;
    printf("\n계산중.........\n\n");
    int day = money / (per * 365);
    int ek = money / 100000000;
    printf("축하합니다!\n당신은 하루에 %d원씩만 세이브한다면,\n%d년 뒤에 %d억 자산가가 될 수 있습니다!\n", day, per, ek);
}