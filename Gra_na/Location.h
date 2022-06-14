#pragma once
#include<vector>
#include<map>
#include<string>
#include"Enemy.h"
#include"NPC.h"
#include"Player.h"
using namespace std;

class Location
{
public:
	int houseNum = 0;
	int exitNum = 4;
	Location* lTOP; Location* lBOTTOM; Location* lLEFT; Location* lRIGHT;
	vector<vector<int>> houseLocation{ { 0,0 }, { 0,0 }, { 0,0 }, { 0,0 } };
	vector<vector<int>> treeLocation;
	vector<vector<int>> portalLocation;
	vector<vector<int>> exitLocation{ {0,0,0},{0,0,0},{0,0,0},{0,0,0} };
	vector<vector<int>> itemLocation;
	int itemToUnlock; string unlockText; Location* toBack;
	vector<Enemy*> enemies;
	vector<NPC*> npc;
	int hold;
	std::map<vector<int>, int> item;


	void setHouseLocation(int houseNum, int X, int Y);
	void setExitLocation(int exitNum, int wall, int howFarFromCorner, int widthOfExit);
	void checkIfLeft(Location* lTop, Location* lBottom, Location* lLeft, Location* lRight);
	void pickItem(vector<vector<int>> itemLocation);
	void renderLocation();
	void setLock(int itemId, string text, Location* toBack); //max one lock per location
	void setItemLocation(int X,int Y, int itemId);
	void setTreeLocation(int X,int Y);
	void setEnemyLocation(int yPos, int xPos, int dir, int los) {
		Enemy* e = new Enemy(yPos, xPos, dir, los);
		enemies.push_back(e);
	}
	void setNPCLocation(int yPos, int xPos, string text) {
		NPC* n = new NPC(yPos, xPos, text);
		npc.push_back(n);
	}
	void setPortalLocation(int xPos, int yPos);
	bool requireItem(int id);
	
};

