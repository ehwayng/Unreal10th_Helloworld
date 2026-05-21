#pragma once

enum PlayerState
{
	None = 0,
	Wait = 1 << 0,
	Jump = 1 << 1,
	Attack = 1 << 2,
	Invincible = 1 << 3
};
void Condition(int State);
int AddState(int State, PlayerState newState);
int SubState(int State, PlayerState disState);
int Toggle(int State, PlayerState TogState);