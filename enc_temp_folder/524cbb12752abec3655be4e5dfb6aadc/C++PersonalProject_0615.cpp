#include <iostream>
#include <string>
#include "C++PersonalProject_0615.h"
using namespace std;

//플레이어 기본정보 변수 세팅
std::string PlayerName = nullptr;			//이름
int Level = 1;				//현재 레벨
const int MaxLevel = 50;	//최대 레벨 : 좀 줄일까...? 버거울 것 같기도...
int Money = 10000;			//현재 보유금액
int HP = 100;				//현재 체력
int const MaxHP = 100;		//최대 체력
int Exp = 0;				//현재 경험치
int MaxExp = 100 + ((Level-1) * 50);	//현재 레벨의 최대 경험치 : 1업마다 50씩 늘어나도록 

void PersonalProject_Main()
{	
	PrintInfo();
	//Tutorial();
	//퀘스트, 던전, 미니게임, 내정보, 내장비, 인벤토리 확인 등 공통 선택지 함수
	//선택지 자체를 함
}




void Tutorial()
{
	printf("모험자님의 이름을 알려주세요 : ");
	cin >> PlayerName; //문자열 입력된 것 잘 적용되는지 확인 필요
	printf("%s님, 모험을 시작하신 것을 환영합니다!\n[내 정보]를 확인하기 위해 아무 키나 눌러보세요.\n", PlayerName); //아무키를 어떻게 적용하는지
	PrintInfo();

	//장비창, 인벤토리 안내
	//기본 옵션 안내
}


void BasicOption()
{
}


//내 정보 확인하는 함수
void PrintInfo()
{
	printf("\n==================== INFO ====================\n");
	printf("레벨 : %d\t경 험 치 : %d/%d\n", Level, Exp, MaxExp);
	printf("체력 : %d/%d\t보유금액 : %d원\n", HP, MaxHP, Money);
	printf("==============================================\n");
}

//내 장비 확인하는 함수
void PrintEquip()
{
}

//내 인벤토리 확인하는 함수 => 착용/사용 등 추가 상호작용 필요
void PrintInven()
{
}



//플레이어 레벨별로 다른 경험치와 금액 보상이 적용된 던전, 퀘스트, 미니게임 > class로 묶어야 할까?
void Dungeon(int MyLevel, int MyMaxExp)
{
}

void Quest(int MyLevel, int MyMaxExp)
{
}

void MiniGame(int MyLevel, int MyMaxExp)
{
}
