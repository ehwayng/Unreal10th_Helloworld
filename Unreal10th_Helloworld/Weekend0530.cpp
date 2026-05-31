#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Weekend0530.h"

using namespace std;

void Weekend0530_Run1()
{
	int Y = 0, M = 0, D = 0;
	printf("요일을 도출할 날짜를 연도, 월, 일 순으로 입력하세요 : \n");
	cin >> Y >> M >> D;
	YMD Date(Y, M, D);		// 입력한 날짜를 기준으로 구조체 생성
	
	PrintYMD(Date);			// 요일 출력
}


//생성된 구조체의 년월일과 요일을 출력하는 함수
void PrintYMD(YMD& InputDate)
{
	printf("입력한 %d년 %d월 %d일은 [%s요일]입니다.\n", InputDate.Year, InputDate.Month, InputDate.Day, InputDate.DayName.c_str());
}

//윤년 판별 함수
bool isLeapYear(int yearcount) {
	return (yearcount % 4 == 0 && yearcount % 100 != 0) || (yearcount % 400 == 0);
	}

//입력된 년월일의 요일을 계산하는 함수
std::string ReturnDay(int InYear, int InMonth, int InDay)
{
	std::string Result;

	//총 일수
	int SumDay = 0;
	
	for (int y = 1; y < InYear; y++)	//작년까지 연도별 일수 더하기 (윤년 처리)
	{
		if (isLeapYear(y))
		{
			SumDay += 366;
		}
		else
		{
			SumDay += 365;
		}
	}

	int DaysinMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//월별 일수 배열
	
	if (isLeapYear(InYear))		//입력된 연도가 윤년일 경우 2월을 29일로 변경해주기
	{
		DaysinMonth[2] = 29;
	}
	for (int i = 1; i < InMonth; i++)	//전달까지 월별 일수 더하기
	{
		SumDay += DaysinMonth[i];
	}


	//마지막 일수 더해서 총 일수 도출 후 요일 구하기
	SumDay += InDay;

	if (SumDay % 7 == 0)
	{
		Result = "일";
	}
	else if (SumDay % 7 == 1)
	{
		Result = "월";
	}
	else if (SumDay % 7 == 2)
	{
		Result = "화";
	}
	else if (SumDay % 7 == 3)
	{
		Result = "수";
	}
	else if (SumDay % 7 == 4)
	{
		Result = "목";
	}
	else if (SumDay % 7 == 5)
	{
		Result = "금";
	}
	else
	{
		Result = "토";
	}

	return Result;
}


//===================================================

Cards deck[52];
int IndexDeck = 0;

Cards DrawCard() {
	Cards PickedCard = deck[IndexDeck];
	IndexDeck++;
	return PickedCard;
}

void Weekend0530_Run2()
{
	// 카드 이름과 실제 매칭될 점수 배열
	std::string Names[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int Values[13] = { 11,   2,   3,   4,   5,   6,   7,   8,   9,  10,  10,  10,  10 };			// A 일단 11점

	// 52장 카드덱 채우기
	int CurrentDeckSize = 0;

	for (int count = 0; count < 4; count++)		// 4번 반복
	{
		for (int n = 0; n < 13; n++)
		{
			deck[CurrentDeckSize].CardName = Names[n];
			deck[CurrentDeckSize].Value = Values[n];
			CurrentDeckSize++;
		}
	}

	// 덱 무작위로 섞기 (셔플)
	for (int i = 0; i < 52; i++) {
		int RandomIndex = rand() % 52;

		Cards Temp = deck[i];
		deck[i] = deck[RandomIndex];
		deck[RandomIndex] = Temp;
	}

	Participant Player;
	Participant Dealer;

	// 2장씩 배분 후 출력
	Player.AddCard(DrawCard());		
	Dealer.AddCard(DrawCard());
	Player.AddCard(DrawCard());
	Dealer.AddCard(DrawCard());

	printf("플레이어 카드 : %s, %s\n", Player.InHand[0].CardName.c_str(), Player.InHand[1].CardName.c_str());
	printf("딜러 카드 : %s, (1장 비공개)\n", Dealer.InHand[0].CardName.c_str());

	// 누군가 블랙잭일 경우
	if (Player.IsBlackjack() || Dealer.IsBlackjack())
	{
		if (Player.IsBlackjack() && Dealer.IsBlackjack())
		{
			printf("무승부입니다.\n");
		}
		else if (Player.IsBlackjack())
		{
			printf("플레이어 블랙잭! 플레이어 승리\n");
		}
		else
		{
			printf("딜러 블랙잭! 딜러 승리\n");
		}
		return;
	}

	// 플레이어 턴
	while (true)	{
		if (Player.GetScore() > 21)
		{
			printf("플레이어 버스트! 플레이어패배.\n");
			break;
		}

		std::string Choice;
		printf("현재 점수 : %d\n", Player.GetScore());
		printf("Hit(카드 추가)와 Stand(멈추기) 중 선택하세요 : ");
		cin >> Choice;

		if (Choice == "hit" || Choice == "Hit")
		{
			Player.AddCard(DrawCard());		// 덱에서 1장 더 추가

			// 현재 들고 있는 카드 출력
			printf("현재 보유 카드: ");
			for (int i = 0; i < Player.CardCount; i++)
			{
				printf("%s ", Player.InHand[i].CardName.c_str());
			}
			printf("\n");
		}
		else if (Choice == "stand" || Choice == "Stand")
		{
			break;
		}
	}

	// 딜러 턴
	printf("\n딜러의 비공개 카드 : %s\n", Dealer.InHand[1].CardName.c_str());
	while (Dealer.GetScore() < 17)
	{
		printf("딜러가 카드를 1장 더 뽑습니다.\n");
		Dealer.AddCard(DrawCard());
	}

	// 승패 판정
	int PlayerScore = Player.GetScore();
	int DealerScore = Dealer.GetScore();

	printf("\n최종 점수 : 플레이어 [%d] vs 딜러 [%d]\n", PlayerScore, DealerScore);

	if (DealerScore > 21)
	{
		printf("딜러 버스트! 플레이어 승리\n");
	}
	else if (PlayerScore > DealerScore)
	{
		printf("플레이어 승리!\n");
	}
	else if (PlayerScore < DealerScore)
	{
		printf("딜러 승리!\n");
	}
	else
	{
		printf("무승부!\n");
	}
}




