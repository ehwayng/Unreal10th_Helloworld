#pragma once
#include <iostream>
#include <time.h>

// 기능이 완전히 독립적이라 재활용 용도로 만드는 함수
void PrintCurrentState(int Turn, int BotMoney, int PlayerMoney);
int RandomRange(int Min, int Max);
int InputPlayerBet(int MaxBet);

// 의도를 명확하게 보여주는 용도로 만드는 함수
void DiceGameRun();
int Dice6();

// 각종 수식처럼 자주 변할 수 있는 부분을 쉽게 구분하기 위해 만드는 함수
bool GameClear(int BotMoney, int PlayerMoney);
int GetMaxBet(int BotMoney, int PlayerMoney);
int ReceiveBotBet(int MaxBet);
