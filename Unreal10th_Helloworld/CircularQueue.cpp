#include <iostream>
#include <stack>
#include <string>
#include "CircularQueue.h"

void CircularQueue::Enqueue(int InValue)
{
    if (IsFull())
    {
        printf("ERROR : 큐가 가득 차 있습니다!\n");
        return;
    }
    if (IsEmpty())
    {
        Front = 0;
    }
    Rear = (Rear + 1) % MaxSize;
    Data[Rear] = InValue;
}

int CircularQueue::DeQueue()
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return Empty;
    }

    int Value = Data[Front];
    if (Front == Rear)
    {
        Front = Empty;
        Rear = Empty;
    }
    else
    {
        Front = (Front + 1) % MaxSize;
    }
    return Value;
}

inline void CircularQueue::Print() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return;
    }
}

int CircularQueue::Peek() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비었습니다!\n");
        return Empty;
    }
}
