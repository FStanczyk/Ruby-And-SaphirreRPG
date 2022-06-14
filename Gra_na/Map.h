#pragma once
#include "player.h"
#include "Location.h"
#include"Globals.h"

class Map
{
public:
	string roof = " - ";
	string floor = " = ";
	string wall = " | ";
	void initilizeMap();
	void refreshMap(Location currentLocation);
	void drawHouse(int xPos, int yPos);
	void drawExits(int wall, int howFarFromCorner, int widthOfExit);
	void drawItems(int xPos, int yPos);
	void drawTrees(int xPos, int yPos);
	void setLocker(int id, string text, Location* toBack);
	void drawPortals(int xPos, int yPos);
	void spawnEnemies(int yPos, int xPos, int dir, int los);
	void spawnNpc(int yPos, int xPos, string text);
};

