#include <stdio.h>
#include "0521Practice_1.h"

void Condition(int State)		// 현재 플레이어의 상태를 출력하는 함수
{
	printf("\n<현재상태>\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]\n",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X',
		(State & Attack) ? 'O' : 'X',
		(State & Invincible) ? 'O' : 'X');
	return;
}

int AddState(int State, PlayerState newState)		// 특정 상태를 추가하는 함수
{
	return State |= newState;
}

int SubState(int State, PlayerState disState)		// 특정 상태를 해제하는 함수
{
	return State &= ~disState;
}

int Toggle(int State, PlayerState TogState)			// 특정 상태를 토글하는 함수
{
	return State ^= TogState;
}
