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

class DynamicCircularQueue
{
private:
    char* Data;
    int MaxSize;
    int Front = 0;
    int Rear = 0;

public:
    // 생성자에서 동적 할당
    DynamicCircularQueue(int Size = 10) {
        MaxSize = Size;
        Data = new char[MaxSize];
    }
    // 소멸자에서 메모리 해제
    ~DynamicCircularQueue() {
        delete[] Data;
    }

    void Enqueue(char InChar) {
        // 원형 큐 만석 체크 공식: (Rear + 1) % MaxSize == Front
        if ((Rear + 1) % MaxSize == Front) return;

        Data[Rear] = InChar;
        Rear = (Rear + 1) % MaxSize;
    }

    char Dequeue() {
        if (Front == Rear) return '\0'; // 텅 빔

        char Result = Data[Front];
        Front = (Front + 1) % MaxSize;
        return Result;
    }

    bool IsEmpty() {
        return Front == Rear;
    }
};