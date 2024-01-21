#pragma once

enum GameState
{
	GameStateIntro = 0,
	GameStateTitle,
	GameStateMenu,
	GameStateProc
};

extern GameState gs;

void callGame();
void saveGame();
