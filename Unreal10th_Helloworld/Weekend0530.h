#pragma once
#include <string>

//========================Homework1===========================

void Weekend0530_Run1();

//입력된 년월일의 요일을 도출하는 함수
std::string ReturnDay(int InYear, int InMonth, int InDay);	

struct YMD
{
	std::string DayName = "월";
	int Year = 0;
	int Month = 0;
	int Day = 0;

	YMD(int Y, int M, int D)
	{
		DayName = ReturnDay(Y, M, D);		// 함수 완료하면 위에거 지우고 주석 풀기
		Year = Y;
		Month = M;
		Day = D;
	}
};

//생성된 구조체의 년월일과 요일을 출력하는 함수
void PrintYMD(YMD& InputDate);

//========================Homework2===========================

void Weekend0530_Run2();

struct Cards
{
	std::string CardName;	//카드 이름
	int Value;				//카드 점수
};




struct Participant {
    Cards InHand[20];       //손에 든 카드
    int CardCount = 0;      //들고 있는 카드 개수

    //카드 1장 추가 함수
    void AddCard(Cards NewCard)
    {
        InHand[CardCount] = NewCard;
        CardCount++;
    }

    // 현재 점수 계산
    int GetScore()
    {
        int Score = 0;
        int AceCount = 0;

        for (int i = 0; i < (CardCount - 1); i++)
        {
            for (int j = i + 1; j < CardCount; j++)
            {
                if (InHand[j].Value > InHand[i].Value)      // 두개씩 비교하며 앞쪽으로 값이 큰 카드를 몰아넣기
                {
                    Cards Temp = InHand[i];
                    InHand[i] = InHand[j];
                    InHand[j] = Temp;
                }
            }
        }
        Score = InHand[0].Value + InHand[1].Value;
        if ((InHand[0].CardName == "A") || (InHand[1].CardName == "A"))
        AceCount++;

        while (Score > 21 && AceCount > 0)
        {
            Score -= 10;    //에이스카드를 유리하게 낮춰서 적용
            AceCount--;
        }

        return Score;
    }

    bool IsBlackjack() {
        return (CardCount == 2 && GetScore() == 21);
    }
};



//블랙잭 만들기
//	[게임 목표]
//	두 카드의 합이 21에 가깝게 만들되, 21을 넘지 않는 것이 목표
//	21을 초과하면(버스트, Bust)  즉시 패배
//	배팅은 없음
//	[카드의 값]
//		2~10: 카드 숫자 그대로 점수.
//		J(잭), Q(퀸), K(킹) : 각각 10점.
//		A(에이스) : 1점 또는 11점(유리한 쪽으로 자동 선택).
//	[게임 진행 절차]
//	초기 배분 : 딜러와 플레이어 모두 2장씩 카드를 받음.
//	플레이어의 카드는 2장 모두 공개.
//	딜러는 1장은 공개(오픈 카드), 1장은 비공개(홀 카드).



//	<플레이어 턴> 플레이어 선
//	선택지:
//		Hit(히트) : 카드를 1장 더 받음.
//		Stand(스탠드) : 더 이상 카드를 받지 않고 멈춤.
//		플레이어가 21을 초과하면(버스트) 즉시 패배.
//	<딜러 턴>
//		플레이어가 스탠드를 하면 딜러 차례.
//		딜러는 자신의 카드 합이 17 이상이 될 때까지 계속 히트(카드 받기)해야 함.
//		A가 포함된 "소프트 17"(A + 6 = 7 또는 17)도 멈춤.
//		17 이상이면 멈추고, 21을 넘으면 딜러 패배.
//	<승패 판정>
//		버스트가 아닌 경우, 점수 비교.
//			플레이어가 21에 더 가까우면 승리.
//			동점이면 무승부(Push).
//			딜러가 더 가까우면 패배.
//		블랙잭: 처음 받은 두 장이 A + 10(또는 J, Q, K)이면 블랙잭.일반적으로 블랙잭이 단순 21점보다 우선함.