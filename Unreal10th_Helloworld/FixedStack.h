#pragma once
#include <iostream>
#include <string>

using namespace std;

//class FixedStack
//{
//private:
//	char Data[10];
//	int TopIndex = 0;
//
//public:
//	void Push(int InChar);
//	int Pop();
//	bool IsEmpty();
//};


//가변형으로 만들어보자
class DynamicStack
{
public:
	char* Data = nullptr;
	int MaxSize = 0;		//최대 크기
	int TopIndex = 0;

	//생성자
public:
	DynamicStack() = default;
	//소멸자
	~DynamicStack()
	{
		if (Data != nullptr)
		{
			delete[] Data;
		}
	} 

public:
	void Push(char InChar)
	{
		if (TopIndex >= MaxSize)
		{
			printf("스택이 가득 찼습니다.\n");
			return;
		}
		Data[TopIndex] = InChar;
		TopIndex++;
	}
	
	char Pop()
	{
		if (TopIndex <= 0)
		{
			printf("스택이 비어있습니다.\n");
			return '\0';
		}
		TopIndex--;
		return Data[TopIndex];
	}
};


