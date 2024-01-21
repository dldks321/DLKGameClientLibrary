#include "Intro.h"

#include "Title.h"

void loadIntro()
{

}
void freeIntro()
{

}
void drawIntro(float dt)
{

}
void mouseIntro(int stat, Point2D point)
{
	if (stat == 1)
	{
		freeIntro();

		loadTitle();
		gs = GameStateTitle;
	}
}
//void keyboardIntro();
//void padIntro();
