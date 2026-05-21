#pragma once
// 헤더 파일에는 선언만 넣는다.

// Add라는 이름의 함수를 선언
// Add는 int Num1과 int Num2 두 개의 파라메터를 가지고
// int 타입의 데이터를 리턴한다.
int Add(int Num1, int Num2);
// 빼기 함수 만들기
int Sub(int Num1, int Num2);
// 곱하기 함수 만들기
int Mul(int Num1, int Num2);
// 나누기 함수 만들기
int Div(int Num1, int Num2);

// 리턴값 없음. 파라메터도 없음.
void Test();

float Add(float Num1, float Num2);

// 탬플릿 : 해당 연산이 가능한 모든 타입의 변수에 대해 사용 가능함 (float, string 등)
// 탬플릿은 cpp가 아닌 헤더에 포함되어야 한다.
template <typename T>
T Add(T Num1, T Num2)
{
	T Result = Num1 + Num2;
	return Result;
}


// --------------------실습용 함수------------------------ //
