#pragma once

// 데이터는 int
class CircularQueue
{
public:
	void Enqueue(int InValue);
	int DeQueue();
	int Peek() const;
	inline void Print() const;
	

private:
	static constexpr int MaxSize = 10;
	static constexpr int Empty = -1;

	int Data[MaxSize];
	int Front;
	int Rear;

public:
	inline bool IsFull() const { return (Rear + 1) % MaxSize == Front; }
	inline bool IsEmpty() const { return Front == Empty; }
	inline int GetSize() const { return (Rear - Front + MaxSize) % MaxSize + 1; }
};

