#include <iostream>
#pragma once

template <typename T>
class TemplateStack
{
public:
	void Push(T InValue)
	{
		if (IsFull())
		{
			printf("Push 불가! 스택이 이미 가득 찼습니다.\n");
			return;
		}
		Data[TopIndex] = InValue;
		TopIndex++;
	}

	T Pop()
	{
		if (IsEmpty())
		{
			printf("Pop 불가! 스택이 비어있습니다.\n");
			return Empty;
		}
		T Result = Data[TopIndex];
		TopIndex--;
		return Result;
	}

	T Top()
	{
		if (IsEmpty())
		{
			printf("확인 불가! 스택이 비어있습니다.\n");
			return Empty;
		}
		return Data[TopIndex];
	}

	inline bool IsFull() const { return TopIndex == (StackCapacity - 1); }
	inline bool IsEmpty() const { return TopIndex == Empty; }
	inline int GetSize() const { return TopIndex + 1; }

private:
	static constexpr int StackCapacity = 10;
	static constexpr int Empty = -1;

	T Data[StackCapacity];
	T TopIndex = Empty;
};