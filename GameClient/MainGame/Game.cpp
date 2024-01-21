#include "Game.h"

#include "Intro.h"
#include "Title.h"
#include "Menu.h"
#include "Proc.h"

void loadGame()
{
	callGame();// call save file data....

	loadIntro();
	gs = GameStateIntro;
}
void freeGame()
{
	switch (gs) {
	case GameStateIntro: freeIntro(); break;
	case GameStateTitle: freeTitle(); break;
	case GameStateMenu: freeMenu(); break;
	case GameStateProc: freeProc(); break;
	}
}
void drawGame(float dt)
{
	switch (gs) {
	case GameStateIntro: drawIntro(dt); break;
	case GameStateTitle: drawTitle(dt); break;
	case GameStateMenu: drawMenu(dt); break;
	case GameStateProc: drawProc(dt); break;
	}
}
void mouseGame(int stat, Point2D point)
{
	switch (gs) {
	case GameStateIntro: mouseIntro(stat, point); break;
	case GameStateTitle: mouseTitle(stat, point); break;
	case GameStateMenu: mouseMenu(stat, point); break;
	case GameStateProc: mouseProc(stat, point); break;
	}
}