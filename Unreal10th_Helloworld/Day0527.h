#pragma once

void Day0527();

int MyStrLen(const char* str);

// 간단 실습
//1. MyStrCpy
//2. MyStrCat
//3. MyStrCmp
//4. MyAtoI
//5. MyAtoF
//위 함수들 만들기. 파라메터와 리턴 타입은 원본과 같이 만들기.

char* MyStrCpy(char* Destination, const char* Source);

char* MyStrCat(char* Destination, const char* Source);

int MyStrCmp(const char* Str1, const char* Str2);

int MyAtoI(const char* Source);

float MyAtoF(const char* Source);

int FloatCmp(float Num1, float Num2);

// int* ____ = 어떤 정수가 있는 메모리의 가장 첫번째 주소의 값. 해당 정수가 변해도 주소는 변하지 않는다.
// int* ____ = &Integer		>>	Interger가 있는 주소를 호출하는 것