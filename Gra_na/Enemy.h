#pragma once
class Enemy
{
public:
	int yPos = 0, xPos = 0;
	int direction = 0, lineOfSight = 0; //dir 0=N, 1=S, 2=Left, 3=Right
	Enemy(int yPos, int xPos, int dir, int los) :yPos(yPos), xPos(xPos), direction(dir), lineOfSight(los) {};
};
