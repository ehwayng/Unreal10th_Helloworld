#pragma once

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
	char* Data;
	int MaxSize;	//최대 크기
	int TopIndex = 0;

	//생성자
public:
	DynamicStack() = default;
	//소멸자
	~DynamicStack() = default;

public:
	void Push(int InSize, char* InStr);
	int Pop();
};


