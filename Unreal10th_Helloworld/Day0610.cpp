#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <set>
#include <map>

#include "Day0610.h"
#include "BitFlag.h"
#include "BinarySearchTree.h"
#include "T_FixedStack.h"
#include "LinkedList.h"


	/* 템플릿 클래스 */
	//	- 템플릿 함수와 같음. 코드 중복을 줄이는 것이 목적.
	//	- 컴파일 타임에 템플릿을 사용하는 코드가 나오면 컴파일러가 생성(템플릿 인스턴스화)

	/*===================================================================================*/

	/* 트리 */
	//	- 특징 : 데이터 단위 [Node = 데이터 + 자식]
	//		* 부모-자식 관계를 가지는 계층적 구조를 나타내는 자료구조
	//		* 하나의 Root(뿌리)에서 시작하여 가지가 뻗어나가는 형태
	//		* 순환이 없는 그래프의  한 종류
	//		* 대표적인 비선형 자료구조
	//	- 장점
	//		* 계층적인 데이터를 표현하기에 최적화
	//		* 탐색과 정렬이 매우 효육적 (이진 탐색 트리 계열)
	//		* 배열과 리스트의 장점을 둘 다 보유(탐색이 빠르면서 삽입/삭제도 바르고 크기도 동적)
	//	- 단점
	//		* 구조가 복잡하고 구현이 어려울 수 있다.
	//		* 데이터를 추가/삭제하는 과정이 복잡할 수 있다. (균형을 맞춰야 할 때)
	//	- 이진 트리 : 자식이 최대 2개인 트리
	//	- 전위 순회(PreOrder) : 루트 > 왼쪽 > 오른쪽		
	//	- 중위 순회(InOrder) : 왼쪽 > 루트 > 오른쪽
	//	- 후위 순회(PostOrder) : 왼쪽 > 오른쪽 > 루트

	/*===================================================================================*/

	/* set(집합) */
	//	- 자동정렬, 중복불가, 빠른탐색(레드-블랙트리 알고리즘, O(logN))
	//	- 사용처
	//		* 데이터의 유일서, 정렬, 빠른 검색이 필요할 때 유용
	//
	/* map */
	//	- Key와 Value를 쌍으로 묶어 저장, 키는 중복
	//		* 금지, 자동정렬, 빠른탐색
	//	- 사용처
	//		* 데이터에 중복이 없는 키 값이 설정되어 있고, 필요할 때 빠르게 찾아야 하는 경우 유용
	//		* 리소스 관리자, 데이터 드리븐, 다국어 지원 등등                                      
	
	/* unordered_map */
	//	- Key와 Value를 쌍으로 묶어 저장, 키는 중복금지, 빠른탐색(해시테이블(O(1))
	//	- 사용처
	//		* map을 써야 하는데 정렬이 필요없는 경우(무조건)
	//		* 리소스 관리자, 데이터 드리븐, 다국어 지원 등


void Day0610::TestMain()
{
	TestTemplateClass();
	TestTree();
	TestSet();
	TestMap();
}

void Day0610::TestTemplateClass()
{
	TestEnumClass Test1 = TestEnumClass::Up;
	TestEnumClass Test2 = TestEnumClass::Down;
	TestEnumClass Test3 = Test1 | Test2;

	Calculator MyCalc;

	auto Sum = MyCalc.Add(10, 2.5);
}

void Day0610::TestTree()
{
	BinarySearchTree bst;

	//데이터 삽입
	printf("==== BST 삽입 ====\n");
	int values[] = { 50,30,70,20,40,60,80 };
	int size = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < size; i++)
	{
		bst.Insert(values[i]);
		printf("%d 삽입\n", values[i]);
	}

	//순회 출력
	printf("\n==== 순회 결과 ====\n");
	bst.PrintInOrder();
	bst.PrintPreOrder();
	bst.PrintPostOrder();

	//검색
	printf("\n==== 검색 ====\n");
	int searchKeys[] = { 40,25,80,100 };
	int searchSize = sizeof(searchKeys) / sizeof(searchKeys[0]);

	for (int i = 0; i < searchSize; i++)
	{
		TreeNode* found = bst.Search(searchKeys[i]);
		if (found != nullptr)
		{
			printf("%d : 찾음 (노드 주소 : %p)\n", searchKeys[i], found);
		}
		else
		{
			printf("%d : 없음\n", searchKeys[i]);
		}
	}

	//삭제
	printf("\n==== 삭제 ====\n");
	int deleteKeys[] = { 20,30,50 };
	int deleteSize = sizeof(deleteKeys) / sizeof(deleteKeys[0]);

	for (int i = 0; i < deleteSize; i++)
	{
		printf("%d 삭제\n", deleteKeys[i]);
		bst.Delete(deleteKeys[i]);
		bst.PrintInOrder();
	}
}


void Day0610::TestSet()
{
	std::set<int> MySet;
	MySet.insert(10);
	MySet.insert(50);
	MySet.insert(30);
	MySet.insert(10);
	PrintSet(MySet);

	//MySet.size();	//크기

	std::set<int>::iterator iter = MySet.find(50);	//값이 아니라 이터레이터를 리턴
	int findValue = (*iter);

	MySet.erase(30);	//특정 값을 가진 것을 삭제
	PrintSet(MySet);

	MySet.clear();		//모두 삭제
	PrintSet(MySet);

	// MySet.empty();		//비어있는지 아닌지 확인(bool)
	
	

	std::set<SetTestData> Data;
	Data.insert(SetTestData(10, 20.0f));
	Data.insert(SetTestData(15, 25.0f));
	Data.insert(SetTestData(25, 20.5f));

	std::set<SetTestDataFail> Data2;
	/*Data2.insert(SetTestDataFail(10, 20.0f));		=> 사용하려고 하면 연산자가 오버라이드되지 않아 비교할수가 없어서 컴파일 에러를 띄움
	Data2.insert(SetTestDataFail(15, 25.0f));
	Data2.insert(SetTestDataFail(25, 20.5f));*/

	std::set<SetTestDataFunctor, ComepareTest> Data3;
	Data3.insert(SetTestDataFunctor(10, 20.0f));
	Data3.insert(SetTestDataFunctor(15, 20.5f));
	Data3.insert(SetTestDataFunctor(25, 25.0f));

	int i = 0;
}

void Day0610::PrintSet(const std::set<int>& InTarget)
{
	printf("Set 출력 : ");
	for (int Element : InTarget)
	{
		printf("%d ", Element);
	}
	printf("\n");
}

void Day0610::TestMap()
{
	std::map<CharacterType, CharacterData> Characters;
	Characters[CharacterType::Warrior] = { 12,150,0 };

	CharacterData& WarriorData = Characters[CharacterType::Warrior];
	WarriorData.HP = 200;

	CharacterData& Mage = Characters[CharacterType::Mage];
	Mage.Level = 20;

	CharacterData& Bug = Characters[(CharacterType)35];
	int i = 0;
	
	//std::map<CharacterType, CharacterData>::iterator iter = Characters.find(CharacterType::Cheif);
	auto iter = Characters.find(CharacterType::Cheif);
	if (iter != Characters.end())
	{
		printf("있다.\n");
	}
	else
	{
		printf("없다.\n");
	}

	Characters.insert(std::pair< CharacterType, CharacterData>(CharacterType::Mage, { 12,150,0 }));

	//for (const auto& pair : Characters)
	//{
	//	pair.first;		//키
	//	pair.second;	//value
	//}
}

void Day0610::Practice0610()
{
	TemplateStack<int> MyIntStack;
	TemplateStack<char> MyCharStack;

	//1. 초기 상태 테스트
	printf("스택이 비었나요? %s\n", MyIntStack.IsEmpty() ? "예" : "아니오");

	//2. Push 테스트
	printf("\n");
	printf("Push => 20\n");
	MyIntStack.Push(20);
	printf("Top: %d, Size: %d\n", MyIntStack.Top(), MyIntStack.GetSize());

	printf("Push => 30\n");
	MyIntStack.Push(30);
	printf("Top: %d, Size: %d\n", MyIntStack.Top(), MyIntStack.GetSize());

	printf("Push => 40\n");
	MyIntStack.Push(40);
	printf("Top: %d, Size: %d\n", MyIntStack.Top(), MyIntStack.GetSize());

	//3. Pop 테스트
	printf("\nPOP 실행");
	MyIntStack.Pop();
	printf("Top: %d, Size: %d\n", MyIntStack.Top(), MyIntStack.GetSize());
}
