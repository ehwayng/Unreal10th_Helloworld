#include <iostream>
#include <string>
#include <stack>
#include "Day0609.h"
#include "FixedStack.h"
#include "CircularQueue.h"
using namespace std;
		
int Day0609()
{
	// 스택(Stack)
	// 특징 : 후입선출(Last In First Out, LIFO) 구조
	// 구조
	//	*속성(맴버 변수) - Top : 데이터 입출력 위치
	//	*기능(맴버 함수) - Push : Top에 데이터 추가 / Pop : Top에서 데이터 가져오기
	// 장점
	//	*구조가 단순하다 => 구현이 쉽다
	//	*데이터 저장 및 읽기 속도가 빠르다
	//   적절한 사용 예시
	// 단점

	// 간단실습
	// 1. FixedStack 구현하기
	// 2. 문자열 입력받고 거꾸로 출력하기 (FixedStack과 std::stack 둘 다 해보기)
	
	/*std::string TestString;
	printf("문자를 입력하세요 : ");
	std::cin >> TestString;

	FixedStack MyStack;

	for (char c : TestString)
	{
		MyStack.Push(static_cast<int>(c));
	}
	
	std::string ReverseString;
	while (!MyStack.IsEmpty())
	{
		char Temp[2] = { static_cast<char>(MyStack.Pop()), '\0' };
		ReverseString.append(Temp);
	}*/

	// 큐(Queue)
	// 특징
	//	- 선입선출 구조(First In First Out, FIFO)
	//	- 가장 먼저 들어온 데이터가 가장 먼저 나간다. (줄서기, 번호표 등)
	//	- Rear에 데이터를 추가(Enqueue)하고, Front에서 데이터를 삭제(Deaueue).
	// 장점
	//	- 데이터가 들어온 순서대로 처리해야 할 때 유용함.
	//	- 대기표, 매칭 큐, 메세지 큐 등에 활용됨.
	// 단점
	//	- 중간에 있는 데이터에는 접근하거나 탐색할 수 없음.
	//	- 활용도가 제한적.


	//=============================================================
	//실습 : 작성한 FixedStack과 CircularQueue를 가변형으로 만들기

	DynamicStack* MyDynamicStack = new DynamicStack();

	printf("입력하려는 문자열의 길이를 입력하세요 : ");
	cin >> MyDynamicStack->MaxSize;
	MyDynamicStack->Data = new char[MyDynamicStack->MaxSize];

	string Input;
	printf("문자열을 영어로 입력하세요 : ");
	cin >> Input;
	
	for (char c : Input)
	{
		MyDynamicStack->Push(c);
	}

	printf("Pop한 결과 : ");
	while (MyDynamicStack->TopIndex > 0)
	{
		printf("%c", MyDynamicStack->Pop());
	}
	printf("\n");
	delete MyDynamicStack;
	return 0;

	//======================================================여기 왜 안되냐==

	string TestString;
	printf("원형 큐에 입력할 문자열을 입력하세요: ");
	cin >> TestString;

	// 크기를 15로 지정해서 가변형 원형 큐를 만듭니다. (내가 원하는 크기 지정 가능!)
	DynamicCircularQueue MyQueue(15);

	printf("큐에 데이터 Enqueue 중...\n");
	for (char c : TestString) {
		MyQueue.Enqueue(c);
	}

	printf("데이터 Dequeue 결과 : ");
	// 큐가 텅 빌 때까지 데이터를 하나씩 빼서 출력합니다.
	while (!MyQueue.IsEmpty()) {
		printf("%c", MyQueue.Dequeue());
	}
	printf("\n");
}