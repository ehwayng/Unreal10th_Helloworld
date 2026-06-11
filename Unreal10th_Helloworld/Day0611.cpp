#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include "Day0611.h"
#include "TLinkedList.h"
#include "T_FixedStack.h"

void Day0611::Day0611_Main()
{
	//TestTLinkedList();
	//TestTLinkedList2();
	//TestTStack();
	//TestSTL_Algorithm();
	//TestLambda();
	Practice0611();
}

void Day0611::TestTLinkedList()
{
	TLinkedList<int>* MyList = nullptr;
	MyList = new TLinkedList<int>();

	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10);
	MyList->Add(20);
	MyList->Add(30);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	MyList->InsertAt(40, 100);
	MyList->PrintList();
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가, 위치 2에 15 추가):\n");
	MyList->InsertAt(5, 0);
	MyList->PrintList();
	MyList->InsertAt(15, 2);
	MyList->PrintList();

	printf("\n--- 2. Remove 테스트 ---\n");
	printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
	MyList->Remove(20);
	MyList->PrintList();
	printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
	MyList->Remove(99);
	MyList->PrintList();

	printf("\n--- 3. RemoveAt 테스트 ---\n");
	printf("3-1. 위치가 Size와 같거나 클 때:\n");
	MyList->RemoveAt(5); // 현재 크기는 5이므로, 인덱스 5는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
	int ValueToFind = 30;
	TListNode<int>* FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %d)\n", ValueToFind, (void*)FoundNode, FoundNode->Data);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123;
	FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다.\n", ValueToFind);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Day0611::TestTLinkedList2()
{
	TLinkedList<float>* MyList = nullptr;
	MyList = new TLinkedList<float>();

	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10.0f);
	MyList->Add(20.0f);
	MyList->Add(30.0f);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	MyList->InsertAt(40.0f, 100);
	MyList->PrintList();
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가, 위치 2에 15 추가):\n");
	MyList->InsertAt(5.0f, 0);
	MyList->PrintList();
	MyList->InsertAt(15.0f, 2);
	MyList->PrintList();

	printf("\n--- 2. Remove 테스트 ---\n");
	printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
	MyList->Remove(20.0f);
	MyList->PrintList();
	printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
	MyList->Remove(99.0f);
	MyList->PrintList();

	printf("\n--- 3. RemoveAt 테스트 ---\n");
	printf("3-1. 위치가 Size와 같거나 클 때:\n");
	MyList->RemoveAt(5); // 현재 크기는 5이므로, 인덱스 5는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
	float ValueToFind = 30.0f;
	TListNode<float>* FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾았습니다. (주소: "
			<< (void*)FoundNode << ", 데이터: " << FoundNode->Data << ")" << std::endl;
	}
	else
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾지 못했습니다.\n";
	}
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123.0f;
	FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾았습니다.\n";

	}
	else
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾지 못했습니다.\n";
	}

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Day0611::TestTStack()
{
//	TemplateStack<int> TestStack1;	// 10개짜리	
//	TestStack1.Push(10);
//	TestStack1.Push(20);
//	TestStack1.Push(30);
//	TestStack1.Push(40);
//	TestStack1.Push(50);
//	TestStack1.Push(15);
//	TestStack1.Push(25);
//	TestStack1.Push(35);
//	TestStack1.Push(45);
//	TestStack1.Push(55);
//	TestStack1.Push(100);
//
//	int Value = *(TestStack1.Top());
//	TestStack1.Pop();
//	Value = *(TestStack1.Top());
//	TestStack1.Pop();
//	Value = *(TestStack1.Top());
//	TestStack1.Pop();
//	Value = *(TestStack1.Top());
//	TestStack1.Pop();
//	Value = *(TestStack1.Top());
//	TestStack1.Pop();
//	Value = *(TestStack1.Top());
//
//	TemplateStack<float, 3> TestStack2;	// 3개짜리
//	TestStack2.Push(10.0f);
//	TestStack2.Push(20.0f);
//	TestStack2.Push(30.0f);
//	TestStack2.Push(40.0f);
//	TestStack2.Pop();
//	TestStack2.Pop();
//	TestStack2.Pop();
//	TestStack2.Pop();
}

void Day0611::TestSTL_Algorithm()
{
	std::vector<int> Datas = { 10,35,55,22,47 };
	PrintVector(Datas);

	//데이터 찾기
	std::vector<int>::iterator findIter = std::find(Datas.begin(), Datas.end(), 55);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.\n", (*findIter));
	}
	else
	{
		printf("찾는 수가 없다.\n");	//end는 (*findIter) 이렇게 접근할 수 없음
	}

	findIter = std::find(Datas.begin(), Datas.end(), 100);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.\n", (*findIter));
	}
	else
	{
		printf("찾는 수가 없다.\n");
	}

	//오름차순으로 정렬
	std::sort(Datas.begin(), Datas.end());
	PrintVector(Datas);

	//이진 탐색
	if (std::binary_search(Datas.begin(), Datas.end(), 55))
	{
		printf("%d를 찾았다.\n", (*findIter));
	}
	else
	{
		printf("찾는 수가 없다.\n");
	}
}

void Day0611::PrintVector(const std::vector<int>& InData)
{
	printf("Data : ");
	for (int e : InData)
	{
		printf("%d ", e);
	}
	printf("\n");
}

void Day0611::PrintCharVector(const std::vector<char>& InData)
{
	printf("Data : ");
	for (char c : InData)
	{
		printf("%c ", c);
	}
	printf("\n");
}

void Day0611::TestLambda()
{
	std::vector<int> Datas = { 10,35,55,22,47 };
	PrintVector(Datas);
	
	//오름차순 정렬 
	std::sort(Datas.begin(), Datas.end());
	PrintVector(Datas);


	//내림차순 정렬 (람다 활용)
	std::sort(Datas.begin(), Datas.end(), [](int a, int b) {return a > b; });
	PrintVector(Datas);
	



	int Line = 30;
	auto iter = std::find_if(Datas.begin(), Datas.end(),
		[Line](int n) {
			return n > Line;
		});
	printf("%d보다 큰 첫번째 숫자는 %d입니다.\n", Line, *iter);
}

void Day0611::Practice0611()
{
	// (실습) STL을 활용하여 다음과 같은 작업 진행하기
	//	- 정수를 여러 개 입력받고, 최대/최소 구하기
	//	- 정수를 여러 개 입력받고, 중복 없는 결과를 출력하기
	//	- 문자열에서 중복되는 글자 제거하기
	//	- 문자를 입력받아 각 단어가 등장하는 횟수 측정하기

	printf("1. 정수 입력 -> 최대/최소 구하기\n\n");

	std::vector<int> Integer;
	int Num1 = 0, Num2 = 0, Num3 = 0, Num4 = 0, Num5 = 0;	//벡터 및 변수 생성

	printf("임의의 정수 5개를 입력하시옹 : ");
	std::cin >> Num1 >> Num2 >> Num3 >> Num4 >> Num5;		//변수 입력받고 벡터에 삽입
	Integer.push_back(Num1);
	Integer.push_back(Num2);
	Integer.push_back(Num3);
	Integer.push_back(Num4);
	Integer.push_back(Num5);
	PrintVector(Integer);									//벡터 출력
	std::sort(Integer.begin(), Integer.end());				//오름차순 정렬
	printf("최댓값은 %d, 최솟값은 %d입니다.\n\n", Integer[4], Integer[0]);

	printf("=======================================================\n");
	/***********************************************************************************/

	printf("2. 정수 입력 -> 중복 없이 출력하기\n\n");

	Integer.clear();										//정수 벡터 비우고 재활용 ㅋ
	int Num6 = 0, Num7 = 0, Num8 = 0, Num9 = 0, Num10 = 0;	//변수 5개 더 생성
	printf("임의의 정수 10개를 입력하시옹 : ");
	std::cin >> Num1 >> Num2 >> Num3 >> Num4 >> Num5 >> Num6 >> Num7 >> Num8 >> Num9 >> Num10;
	Integer.push_back(Num1);
	Integer.push_back(Num2);
	Integer.push_back(Num3);
	Integer.push_back(Num4);
	Integer.push_back(Num5);
	Integer.push_back(Num6);
	Integer.push_back(Num7);
	Integer.push_back(Num8);
	Integer.push_back(Num9);
	Integer.push_back(Num10);
	
	std::sort(Integer.begin(), Integer.end());
	printf("\n...중복된 입력을 제거중...\n\n[결과]\n");
	for (int i = Integer.size() - 1; i > 0; i--)
	{
		if (Integer[i] == Integer[i - 1])
		{
			Integer.erase(Integer.begin() + i);
		}
	}
	//Integer.erase(std::unique(Integer.begin(), Integer.end()), Integer.end());
	PrintVector(Integer);

	printf("=======================================================\n");
	/***********************************************************************************/

	printf("\n3. 문자열 내 중복되는 글자 제거하기\n\n");

	std::string TempString;
	printf("문자열을 입력하세요 : ");
	std::cin >> TempString;

	std::vector<char> Character;
	Character.assign(TempString.begin(), TempString.end());
	for (int j = 0; j < Character.size() - 1; j++)
	{
		for (int p = j + 1; p < Character.size();)
		{
			if (Character[j] == Character[p])
			{
				Character.erase(Character.begin() + p);
			}
			else
			{
				p++;
			}
		}
	}
	PrintCharVector(Character);

	printf("=======================================================\n");
	/***********************************************************************************/

	printf("\n4. 문장 내 특정 단어 카운팅\n\n");

	std::string Sentence;
	printf("문장을 입력하세요 : ");
	std::cin.ignore();
	std::getline(std::cin, Sentence);

	std::stringstream SenChar(Sentence);

	std::string KeyWord; // 잘려 나온 단어를 담을 변수
	std::string You = "you";
	std::string It = "it";
	std::string Love = "love";

	int YouCount = 0;
	int ItCount = 0;
	int LoveCount = 0;


	while (SenChar >> KeyWord)
	{
		if (KeyWord == You)
		{
			YouCount++;
		}
		else if (KeyWord == It)
		{
			ItCount++;
		}
		else if (KeyWord == Love)
		{
			LoveCount++;
		}
	}

	// 결과 출력
	printf("\"%s\" : %d번\n", You.c_str(), YouCount);
	printf("\"%s\" : %d번\n", It.c_str(), ItCount);
	printf("\"%s\" : %d번\n", Love.c_str(), LoveCount);
}

