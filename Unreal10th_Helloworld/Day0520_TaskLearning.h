#pragma once

int main()
{
	printf("1. 캐릭터 상태 변환 구현\n\n");
	enum PlayerState
	{
		None = 0,
		Wait = 1 << 0,	// 0001
		Jump = 1 << 1,	// 0010
		Attack = 1 << 2,	// 0100
		Invincible = 1 << 3	// 1000
	};

	int State = None;
	// 플레이어의 상태를 대기로 설정
	State |= Wait;			// State에 Wait을 Or 시키고 저장해라

	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');


	// 점프 상태 추가
	State |= Jump;			// State에 Jump를 Or 시키고 저장해라
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');
	// 공격 상태 추가
	State |= Attack;		// State에 Attack을 Or 시키고 저장해라
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');
	// 대기 상태 해제
	State &= (~Wait);		// State에 Not시킨 Wait을 And 시키고 저장해라
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');
	// 무적 상태 추가
	State |= Invincible;
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');
	// 무적 상태 토글(XOR 사용)
	State ^= Invincible;
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');




	printf("\n\n\n");
	//-----------------------------------------------------------------------------------

	printf("2. 주사위 게임\n\n");
	srand(time(0));

	int botMoney = 10000;
	int playerMoney = 10000;
	printf("<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
	int botDice;
	int playerDice;

	while ((botMoney > 0) && (playerMoney > 0))
	{
		printf("1차 주사위를 던집니다.\n");
		botDice = rand() % 6 + 1;
		printf("Bot : %d\n", botDice);
		playerDice = rand() % 6 + 1;
		printf("Player : %d\n", playerDice);

		if (botDice > playerDice)
		{
			int bat = 0;
			printf("Player 패배!\n배팅 금액을 제시해 주세요 : ");
			cin >> bat;
			botMoney = botMoney - bat;
			playerMoney = playerMoney - bat;
			printf("\n\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);

			printf("2차 주사위를 던집니다.\n");
			int botDice2;
			int playerDice2;
			botDice2 = rand() % 6 + 1;
			printf("Bot : %d\n", botDice2);
			playerDice2 = rand() % 6 + 1;
			printf("Player : %d\n", playerDice2);
			printf("1차, 2차 주사위의 합 결과\n > Bot [%d] vs Player [%d]\n", botDice + botDice2, playerDice + playerDice2);
			if (botDice + botDice2 > playerDice + playerDice2)
			{
				printf("Bot의 승리입니다! 배팅된 금액은 Bot이 가져갑니다.\n");
				botMoney = botMoney + (bat * 2);
				printf("\n\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
			else if (botDice + botDice2 < playerDice + playerDice2)
			{
				printf("Player의 승리입니다! 배팅된 금액은 Player가 가져갑니다.\n");
				playerMoney = playerMoney + (bat * 2);
				printf("\n\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
			else
			{
				printf("무승부입니다! 배팅된 금액은 사라지고 승부를 이어갑니다.\n");
				printf("\n\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
		}
		else if (botDice < playerDice)
		{
			int bat = 0;
			bat = rand() % 10000 + 1;
			printf("Bot이 %d 원을 배팅했습니다.\n", bat);
			botMoney = botMoney - bat;
			playerMoney = playerMoney - bat;
			printf("\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);

			printf("2차 주사위를 던집니다.\n");
			int botDice2;
			int playerDice2;
			botDice2 = rand() % 6 + 1;
			printf("Bot : %d\n", botDice2);
			playerDice2 = rand() % 6 + 1;
			printf("Player : %d\n", playerDice2);
			printf("1차, 2차 주사위의 합 결과\n > Bot [%d] vs Player [%d]\n", botDice + botDice2, playerDice + playerDice2);
			if (botDice + botDice2 > playerDice + playerDice2)
			{
				printf("Bot의 승리입니다! 배팅된 금액은 Bot이 가져갑니다.\n");
				botMoney = botMoney + (bat * 2);
				printf("\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
			else if (botDice + botDice2 < playerDice + playerDice2)
			{
				printf("Player의 승리입니다! 배팅된 금액은 Player가 가져갑니다.\n");
				playerMoney = playerMoney + (bat * 2);
				printf("\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
			else
			{
				printf("무승부입니다! 배팅된 금액은 사라지고 승부를 이어갑니다.\n");
				printf("\n<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", botMoney, playerMoney);
			}
		}
	}

	printf("잔액이 0 이하인 플레이어가 나와 게임이 종료되었습니다.");



	printf("\n\n\n");
	//-----------------------------------------------------------------------------------
	printf("3. 홀짝 게임\n\n");

	const int InitialMoney = 10000;		// 게임 시작시 플레이어의 돈
	const int MinimumBet = 100;			// 최소 배팅 금액
	const int WinMultiplier = 2;		// 이겼을 때 배율

	int Money = InitialMoney;			// 플레이어의 현재 돈
	int CurrentBat = MinimumBet;		// 현재 배팅 금액

	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정

	srand(Seed);	// 시드값 초기화


	while (Money >= 100)		// 게임종료조건 : 플레이어 소지금 100원 미만일 경우
	{
		// 배팅 - 플레이어는 기본금 100원으로 배팅을 시작
		printf("\n현재 소지금 : [%d]원\n", Money);
		printf("현재 배팅 금액 : [%d]원\n", CurrentBat);
		Money -= CurrentBat;		// 배팅 금액만큼 감소

		// 홀짝 선택 - 플레이어가 1(홀) 또는 2(짝) 선택
		int Select = 0;
		while (Select != 1 && Select != 2)
		{
			printf("홀(1) 또는 짝(2)을 선택하세요 : ");
			cin >> Select;				// 입력받고
			cin.clear();				// 잘못된 입력일 때 에러 리셋
			cin.ignore(10000, '\n');	// 버퍼 비우기
		}

		// 결과 결정 - 컴퓨터가 랜덤으로 1(홀) 또는 2(짝) 선택 > 일치하면 승리(2배 획득), 다르면 패배(배팅금 전액 잃음)
		int Result = rand() % 2 + 1;	// 랜덤으로 1 or 2 고르기
		printf("결과는 [%s]입니다.\n", (Result == 1) ? "홀" : "짝");

		if (Select == Result)
		{
			int WinPrice = CurrentBat * WinMultiplier;		// 승리 상금은 현재 배팅금의 2배
			printf("축하합니다! [%d]원을 획득할 수 있습니다.\n");
			printf("1) [%d]원을 모두 다시 배팅\n", WinPrice);
			printf("2) [%d]원을 받고 다시 [%d]원부터 배팅\n", WinPrice, MinimumBet);
			printf("1 또는 2 중 하나를 선택하세요 : ");
			int KeepGoing = 0;
			while (KeepGoing != 1 && KeepGoing != 2)		// 선택지 입력받기
			{
				cin >> KeepGoing;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (KeepGoing == 1)
			{
				CurrentBat = WinPrice;
			}
			else
			{
				Money += WinPrice;			// 상금을 받고
				CurrentBat = MinimumBet;	// 100원부터 다시 배팅
			}
		}
		else
		{
			printf("안타깝네요! 배팅한 [%d]원을 모두 잃었습니다.\n", CurrentBat);
			CurrentBat = MinimumBet;		// 배팅 금액 초기화
		}
	}
	printf("소지금이 부족해서 더 이상 게임을 진행할 수 없습니다.");



	// -------------내가 한것들--------------
	//int coin = 100;
	//int batCoin = 100;
	//printf("[%d]원 배팅 완료\n\n", batCoin);
	//int select = 0;
	//printf("플레이어는 홀(1)과 짝(2) 중 하나를 선택해 주세요 : ");
	//cin >> select;
	//if (select == 1)
	//{
	//printf("[홀]을 선택하셨습니다.\n");
	//}
	//else
	//{
	//printf("[짝]을 선택하셨습니다.\n");
	//}

	//int botSelect;
	//botSelect = rand() % 2 + 1;	
	//if (botSelect == 1)
	//{
	//	printf("컴퓨터의 선택은 [홀]입니다.\n");
	//}
	//else
	//{
	//	printf("컴퓨터의 선택은 [짝]입니다.\n");
	//}

	//int result = select ^ botSelect;	// 0이면 일치, 1이면 불일치
	//if (result == 0)
	//{
	//	coin =+ batCoin * 2;
	//	printf("홀짝 일치로 플레이어가 배팅한 금액의 2배를 획득했습니다.\n");
	//	printf("현재 잔액 : %d원\n\n", coin);
	//	while (coin >= 100)
	//	{
	//		int batSelect = 0;
	//		printf("다음 게임의 배팅 방식을 선택하세요\n1. 연승도전(전액 배팅)   /   2. 기본도전(100원 배팅)");
	//		cin >> batSelect;
	//		if (batSelect == 1)		// 연승도전
	//		{
	//			batCoin = coin;
	//			printf("배팅 금액 : %d원\n", batCoin);
	//			printf("플레이어는 홀(1)과 짝(2) 중 하나를 선택해 주세요 : ");
	//			cin >> select;
	//			if (select == 1)
	//			{
	//				printf("[홀]을 선택하셨습니다.\n");
	//			}
	//			else
	//			{
	//				printf("[짝]을 선택하셨습니다.\n");
	//			}

	//			int botSelect;
	//			botSelect = rand() % 2 + 1;
	//			if (botSelect == 1)
	//			{
	//				printf("컴퓨터의 선택은 [홀]입니다.\n");
	//			}
	//			else
	//			{
	//				printf("컴퓨터의 선택은 [짝]입니다.\n");
	//			}

	//			if (result == 0)
	//			{
	//				coin =+ batCoin * 2;
	//				printf("홀짝 일치로 플레이어가 배팅한 금액의 2배를 획득했습니다.\n");
	//				printf("현재 잔액 : %d원\n\n", coin);
	//			}
	//			else
	//			{
	//				coin = -batCoin;
	//				printf("홀짝 불일치로 플레이어가 배팅한 금액 전체를 잃었습니다.\n");
	//				printf("현재 잔액 : %d원\n", coin);
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	coin = -batCoin;
	//	printf("홀짝 불일치로 플레이어가 배팅한 금액 전체를 잃었습니다.\n");
	//	printf("현재 잔액 : %d원\n", coin);
	//	printf("홀짝 게임이 종료되었습니다.\n");
	//}


}
//// 간단실습
//
//// 1. 가위바위보 게임 - 3선승제 / enum 활용
//printf("<가위바위보 게임>\n");

//srand(time(0));
//int botRPS;
//int playerRPS = 0;
//int result = 0;	// 0=비김 1=플레이어승 2=컴퓨터승

//enum RPS
//{
//	Scissors = 1,
//	Rock,
//	Paper
//};

//while (result != 0)
//{
//	printf("[1] 가위  [2] 바위  [3] 보\n무엇을 낼지 숫자로 입력하세요 : ");
//	cin >> playerRPS;
//	botRPS = rand() % 3 + 1;
//	if (botRPS = playerRPS)
//	{
//		if (botRPS == 1)
//		{
//		printf("Bot : 가위 / Player : 가위\n");
//		}
//		else if (botRPS == 2)
//		{
//		printf("Bot : 바위 / Player : 바위\n");
//		}
//		else
//		{
//		printf("Bot : 보 / Player : 보\n");
//		}
//	result = 0;
//	printf("비겼습니다!\n\n");
//	}
//	else if (botRPS == 1)
//	{
//		if (playerRPS == 2)
//		{
//			printf("Bot : 가위 / Player : 바위\n");
//			result = 1;
//			printf("승리했습니다!^^\n\n");
//		}
//		else
//		{
//			printf("Bot : 가위 / Player : 보\n");
//			result = 2;
//			printf("패배했습니다!ㅠㅠ\n\n");
//		}
//	}
//	else if (botRPS == 2)
//	{
//		if (playerRPS == 1)
//		{
//			printf("Bot : 바위 / Player : 가위\n");
//			result = 2;
//			printf("패배했습니다!ㅠㅠ\n\n");
//		}
//		else
//		{
//			printf("Bot : 바위 / Player : 보\n");
//			result = 1;
//			printf("승리했습니다!^^\n\n");
//		}
//	}
//	else
//	{
//		if (playerRPS == 1)
//		{
//			printf("Bot : 보 / Player : 가위\n\n");
//			result = 1;
//			printf("승리했습니다!^^\n\n");
//		}
//		else
//		{
//			printf("Bot : 보 / Player : 바위\n\n");
//			result = 2;
//			printf("패배했습니다!ㅠㅠ\n\n");
//		}

//	}

//}

//실습과제

/*printf("1. 캐릭터 상태 변환 구현\n");

enum condition
{
	Jump,
	Attack,
	Standby,
	Invincible
};

int playerCondition = Standby;*/





//// 랜덤
//srand(time(0));		// !랜덤의 시드값을 현재 시간으로 설정하기! (프로그램 실행할 때 한번만 하면 됨)

//int RandomNumber;
//int TestCount = 10000000;
//int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
//for (int i = 0; i < TestCount; i++)
//{
//	RandomNumber = rand() % 6 + 1;	// 1~6이 랜덤으로 골라지게 됨	// rand() - 0에서 RandMax 사이에서 랜덤하게 나옴
//	//printf("Random : %d\n", RandomNumber);
//	switch (RandomNumber)
//	{
//	case 1 :
//		num1++;
//		break;
//	case 2 :
//		num2++;
//		break;
//	case 3 :
//		num3++;
//		break;
//	case 4 :
//		num4++;
//		break;
//	case 5 :
//		num5++;
//		break;
//	case 6 :
//		num6++;
//		break;
//	default :
//		printf("ERROR!! ERROR!! ERROR!!\n");
//		break;
//	}
//}
//printf("num1: [%d]\tnum2: [%d]\tnum3: [%d]\tnum4: [%d]\tnum5: [%d]\tnum6: [%d]", num1, num2, num3, num4, num5, num6);