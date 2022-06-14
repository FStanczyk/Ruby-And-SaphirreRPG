#include <iostream>
#include <string>
#include<vector>
#include "Globals.h"
#include<windows.h>
using namespace std;
const int MAP_SIZE = 26;
const string basePoint = "   ";
const string itemPoint = " # ";
string point[MAP_SIZE][MAP_SIZE];

void Map::initilizeMap() {
	for (int i = 0; i < MAP_SIZE-1; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			point[i][j] = basePoint;
			point[0][j] = " = ";
			point[MAP_SIZE-1][j] = " = ";
		}
		point[i][0] = " | ";
		point[i][MAP_SIZE - 1] = " | ";
	}
}
void Map::refreshMap(Location currentLocation) {
	system("cls");
	player->checkBag(player);
	for (int i = 0; i < currentLocation.houseNum; i++) 
		drawHouse((currentLocation.houseLocation[i][0]), (currentLocation.houseLocation[i][1]));
	
	for (int i = 0; i < currentLocation.exitNum; i++) 
		drawExits(currentLocation.exitLocation[i][0], currentLocation.exitLocation[i][1], currentLocation.exitLocation[i][2]);

	for (auto i: currentLocation.itemLocation)
		drawItems(i[0], i[1]);
	if (currentLocation.toBack) {
		setLocker(currentLocation.itemToUnlock, currentLocation.unlockText, currentLocation.toBack);
	}

	for (auto i : currentLocation.portalLocation)
		drawPortals(i[0], i[1]);
	for(auto i: currentLocation.treeLocation)
		drawTrees(i[0], i[1]);
	for (auto i : currentLocation.npc)
		spawnNpc(i->yPos, i->xPos, i->text);
	for (auto i : currentLocation.enemies)
		spawnEnemies(i->yPos, i->xPos, i->direction, i->lineOfSight);
	currentLocation.pickItem(currentLocation.itemLocation);
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			cout << point[i][j] << flush;
		}
		cout << endl;
	}
}
void Map::spawnEnemies(int yPos, int xPos, int dir, int los) {
	point[yPos][xPos] = " @ ";
	bool inSight = false;
	switch(dir) {
	case 0: {
		for (int i = 0; i < los; i++)
			if (player->Xpos == xPos && player->Ypos == yPos - 1 - i) inSight = true;
		if (inSight) {
			for (int i = 0; i < los; i++)
				point[yPos - 1 - i][xPos] = " # ";
			playing = false;
		}
		if (currentLocation->requireItem(3) == true) {
			for (int i = 0; i < los; i++)
				point[yPos - 1 - i][xPos] = " # ";
		}
		break;
	}
	case 1: {		
		for (int i = 0; i < los; i++)
			if (player->Xpos == xPos && player->Ypos == yPos + 1 + i)inSight = true;
		if (inSight) {
			for (int i = 0; i < los; i++)
				point[yPos + 1 + i][xPos] = " # ";
			playing = false;
		}
		if (currentLocation->requireItem(3) == true) {
			for (int i = 0; i < los; i++)
				point[yPos + 1 + i][xPos] = " # ";
		}
		break; 
	}
	case 2:{		
		for (int i = 0; i < los; i++)
			if (player->Xpos == xPos - 1 - i && player->Ypos == yPos)inSight = true;
		if (inSight) {
			for (int i = 0; i < los; i++)
				point[yPos][xPos - 1 - i] = " # ";
			playing = false;
		}
		if (currentLocation->requireItem(3) == true) {
			for (int i = 0; i < los; i++)
				point[yPos][xPos - 1 - i] = " # ";
		}
		break; 
	}
	case 3:{		
		for (int i = 0; i < los; i++)
			if (player->Xpos == xPos + 1 + i && player->Ypos == yPos)inSight = true;
		if (inSight) {
			for (int i = 0; i < los; i++)
				point[yPos][xPos + 1 + i] = " # ";
			playing = false;
		}
		if (currentLocation->requireItem(3) == true) {
			for (int i = 0; i < los; i++)
				point[yPos][xPos + 1 + i] = " # ";
		}
		break; 
	}
	}
}
void Map:: drawHouse(int xPos, int yPos) {
//      - - - -  
//    - - - - - -
//	- - - - - - - -
//	  |	|	= = |
//	  | |   = = |
//    = = = = = = 
	//floor
	for (int i = 0; i < 6; i++)
		point[yPos][xPos + i] = floor;
	//walls
	point[yPos - 1][xPos] = wall; point[yPos - 2][xPos] = wall;
	point[yPos - 1][xPos + 1] = wall; point[yPos - 2][xPos + 1] = wall;
	point[yPos - 1][xPos + 5] = wall; point[yPos - 2][xPos + 5] = wall;

	//roof
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 8 - 2 * j; i++)
			point[yPos - 3 - j][xPos - 1 + i + j] = roof;
};
void Map::drawExits(int wall, int howFarFromCorner, int widthOfExit) {
	switch (wall) {
	case 0: {
		for (int i = 0; i < widthOfExit; i++)
			point[0][howFarFromCorner + i] = basePoint;
		break;
	}
	case 1: {
		for (int i = 0; i < widthOfExit; i++)
			point[MAP_SIZE - 1][howFarFromCorner + i] = basePoint;
		break;
	}
	case 2: {
		for (int i = 0; i < widthOfExit; i++)
			point[howFarFromCorner + i][0] = basePoint;
		break;
	}
	case 3: {
		for (int i = 0; i < widthOfExit; i++)
			point[howFarFromCorner + i][MAP_SIZE - 1] = basePoint;
		break;
	}
	}
}
void Map::drawItems(int xPos, int yPos) {
	// #
	point[xPos][yPos] = itemPoint;
}
void Map::drawPortals(int xPos, int yPos) {
	//     I
	//	=  X  =
	//     I
	point[yPos][xPos] = " # ";
	point[yPos - 1][xPos] = " | ";
	point[yPos + 1][xPos] = " | ";
	point[yPos][xPos + 1] = " # ";
	point[yPos][xPos - 1] = " # ";
	if (player->Xpos == xPos && player->Ypos == yPos) {
		if (currentLocation->requireItem(1) == true) {
			if (currentLocation->requireItem(2) == true) {
				displayText("You have opened the Portal! You will be remembered forever as the one who escaped!", true);
				displayText("made by Filip Stanczyk. Please check my github: https://github.com/FStanczyk", true);
				playing = false;
			}
			else {
				displayText("You can't open the portal without Ruby!", false); system("cls");
			}
		}
		else {
			displayText("You can't open the portal without Saphirre!", false); system("cls");
		}
	}
}
void Map::setLocker(int id, string text, Location* toBack) {
	if (currentLocation->requireItem(id) == false) {
		if (player->Ypos == 1)player->Ypos = MAP_SIZE - 1;
		else if (player->Ypos == MAP_SIZE - 1)player->Ypos = 1;
		else if (player->Xpos == MAP_SIZE - 1)player->Xpos = 1;
		else if (player->Xpos == 1)player->Ypos = MAP_SIZE - 1;
		displayText(text, false);
		currentLocation = toBack;
		initilizeMap();
		refreshMap(*currentLocation);
		//currentLocation->renderLocation();
	}
}
void Map::spawnNpc(int yPos, int xPos, string text) {
	point[yPos][xPos] = " V ";

	if (player->Ypos == yPos + 1 || player->Ypos == yPos - 1) {
		if (player->Xpos == xPos)
			cout << text << endl;
	}else if (player->Xpos == xPos + 1 || player->Xpos == xPos - 1) {
		if (player->Ypos == yPos)
			cout << text << endl;
	}
			//chat(text, true);
}
void Map::drawTrees(int xPos, int yPos) { //trunk position
	//       o  o 
	//    o  O  O  o
	// o  O  0  0  O  o 
	// o  O  0  0  O  o 
	//       |  |

	point[yPos][xPos] = " | ";
	point[yPos][xPos + 1] = " | ";
	for (int i = 0; i < 2; i++) {
		point[yPos - 3][xPos + i] = " O ";
		point[yPos - 3][xPos-1 + 3*i] = " o ";
		point[yPos - 4][xPos+i] = " o ";
		for (int j = 0; j < 2; j++) {
			point[yPos - 1 - i][xPos + j] = " 0 ";
			point[yPos - 1 - i][xPos - 1 + 3 * j] = " O ";
			point[yPos - 1 - i][xPos - 2 + 5 * j] = " o ";
		}
	}
}
Map* MAP = new Map;