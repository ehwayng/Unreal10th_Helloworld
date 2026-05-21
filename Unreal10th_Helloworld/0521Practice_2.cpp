#include <stdio.h>
#include "0521Practice_2.h"

void PrintCurrentState(int Turn, int BotMoney, int PlayerMoney)
{
	printf("-------- Round %d --------\n", Turn);
	printf("<현재 잔액>\nBot [%d]원\nPlayer [%d]원\n\n", BotMoney, PlayerMoney);
	return;
}

bool GameClear(int BotMoney, int PlayerMoney)
{
	return (BotMoney > 0 && PlayerMoney > 0);
}

int GetMaxBet(int BotMoney, int PlayerMoney)
{
	return (BotMoney < PlayerMoney) ? BotMoney : PlayerMoney;
}

int InputPlayerBet(int MaxBet)
{
	
}

int ReceiveBotBet(int MaxBet)
{
	return 0;
}

