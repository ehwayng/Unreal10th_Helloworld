#pragma once
#include <iostream>
#include <time.h>

unsigned int Seed = (unsigned int)time(0);

void PrintCurrentState(int Turn, int BotMoney, int PlayerMoney);
bool GameClear(int BotMoney, int PlayerMoney);
int GetMaxBet(int BotMoney, int PlayerMoney);
int InputPlayerBet(int MaxBet);
int ReceiveBotBet(int MaxBet);
