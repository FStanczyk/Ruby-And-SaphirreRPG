#include <iostream>
#include <string>
#include"Globals.h"
#include<vector>
#include <algorithm>
#include<map>
void initializeLocations() {
	//here are hardcoded info about locations
	//SPAWN
	Spawn->setExitLocation(0, 1, 3, 5);
	Spawn->setExitLocation(1, 3, 7, 6); //road01
	Spawn->setTreeLocation(6, 10);
	Spawn->setTreeLocation(18, 21);
	Spawn->setItemLocation(2,2,3);
	Spawn->setNPCLocation(2,11,"I heard that you can find portal somewhere in this region... However I couldn't find it, maybe you will get more lucky.");
	Spawn->lBOTTOM = CoastVillage;
	Spawn->lRIGHT = Road01;

	//CoastVillage
	CoastVillage->setExitLocation(0, 0, 3, 5); //spawn
	CoastVillage->setExitLocation(1, 1, 16, 6); //witch
	CoastVillage->setExitLocation(2, 3, 3, 5); //careluan
	CoastVillage->setHouseLocation(0,4,20); CoastVillage->houseNum++;
	CoastVillage->setHouseLocation(1,18,12); CoastVillage->houseNum++;
	CoastVillage->setEnemyLocation(18, 12, 0, 5);
	CoastVillage->setNPCLocation(18, 4, "I live in this village for ten years. Some people are truly crazy here... they think, somewhere behind the forest there is Ruby. Honestly, Iwouldn't believe them.");
	CoastVillage->setNPCLocation(22, 19, "I came here as a little boy, now I am 16! My dad is a hunter, maybe you will find him.");

	CoastVillage->lTOP = Spawn;
	CoastVillage->lRIGHT = CareluanCity;
	CoastVillage->lBOTTOM = WitchHouse;

	//WitchHouse
	WitchHouse->setExitLocation(0, 0, 16, 6); //coastvillage
	WitchHouse->setExitLocation(1, 3, 15, 3); //keychamber
	WitchHouse->setEnemyLocation(7, 24, 0, 5);
	WitchHouse->setHouseLocation(0, 2, 17); WitchHouse->houseNum++;
	WitchHouse->setNPCLocation(20, 4, "People around therecall me Old Witch, but I am completely sane. They call me that because I have 13 kittens and marijuana plantation in the house. Sometimes I think they are just jealous!");
	WitchHouse->setTreeLocation(20, 7);
	WitchHouse->lTOP = CoastVillage;
	WitchHouse->lRIGHT = KeyChamber;

	//Road01
	Road01->setExitLocation(0, 2, 7, 6); //spawn
	Road01->setExitLocation(1, 1, 15, 7); //careluan
	Road01->setExitLocation(2, 3, 4, 4); //grandForest
	Road01->setEnemyLocation(17, 20, 1, 4);
	Road01->setNPCLocation(14, 8, "Be aware of those @ guys, they killed my grandpa when he was biking!");
	Road01->setHouseLocation(0, 16, 7); Road01->houseNum++;
	Road01->setTreeLocation(5, 19);
	Road01->lLEFT = Spawn;
	Road01->lBOTTOM = CareluanCity;
	Road01->lRIGHT = GrandForest;

	//CareluanCity
	CareluanCity->setExitLocation(0, 0, 15, 7); //road01
	CareluanCity->setExitLocation(1, 1, 16, 6); //keyChamber
	CareluanCity->setExitLocation(2, 3, 12, 5); //littledistrict
	CareluanCity->setNPCLocation(11, 5, "In the city we don't believe in these 'crystals', butwho knows... In every legend there must be some glimmer of truth ye?");
	CareluanCity->setNPCLocation(4, 17, "They don't believe you? I have seen the portal a few days ago, however you need both Saphirre and Ruby to activate it. I've heard that saphirre is somewhere in this city.");
	CareluanCity->setNPCLocation(9, 2, "Ruby? I heard it is guarded by @'s, be aware of them!");
	CareluanCity->setEnemyLocation(24, 14, 3, 8);
	CareluanCity->setExitLocation(3, 2, 3, 5); //CoastVillage
	CareluanCity->setHouseLocation(0, 2, 8); CareluanCity->houseNum++;
	CareluanCity->setHouseLocation(1, 3, 21); CareluanCity->houseNum++;
	CareluanCity->setItemLocation(23, 18, 1);
	CareluanCity->setHouseLocation(2, 15, 17); CareluanCity->houseNum++;
	CareluanCity->lTOP = Road01;
	CareluanCity->lBOTTOM = KeyChamber;
	CareluanCity->lLEFT = CoastVillage;
	CareluanCity->lRIGHT = LittleDistrict;

	//KeyChamber
	KeyChamber->setExitLocation(0, 2, 15, 3); //WitchHouse
	KeyChamber->setExitLocation(1, 0, 16, 6); //Careluan
	KeyChamber->setItemLocation(20, 20, 0);
	KeyChamber->lTOP = CareluanCity;
	KeyChamber->lLEFT = WitchHouse;

	//GrandForest
	GrandForest->setExitLocation(0, 2, 4, 4); //Road01
	GrandForest->setNPCLocation(10, 12, "My name is Howard, I am a hunter, you can find some deer and boars but mostly before the dawn.");
	GrandForest->setExitLocation(1, 3, 12, 3); //VaultGuard
	GrandForest->setTreeLocation(15, 18);
	GrandForest->setTreeLocation(8, 13);
	GrandForest->setTreeLocation(19, 24);
	GrandForest->setTreeLocation(4, 23);
	GrandForest->setTreeLocation(17, 7);
	GrandForest->lRIGHT = VaultGuard;
	GrandForest->lLEFT = Road01;

	LittleDistrict->setExitLocation(0, 1, 18, 5); //LastVillage
	LittleDistrict->setExitLocation(1, 2, 12, 5); //Careluan
	LittleDistrict->setHouseLocation(0, 10, 16); LittleDistrict->houseNum++;
	LittleDistrict->setHouseLocation(1, 3, 6); LittleDistrict->houseNum++;
	LittleDistrict->setNPCLocation(11, 5, "This place is not some childish park, stay low you bastard!");
	LittleDistrict->setTreeLocation(18, 22);
	LittleDistrict->setEnemyLocation(16, 10, 1, 8);
	LittleDistrict->setEnemyLocation(8, 23, 2, 10);
	LittleDistrict->lBOTTOM = LastVillage;
	LittleDistrict->lLEFT = CareluanCity;

	//KeyChamber
	//LastVillage
	LastVillage->setExitLocation(0, 0, 18, 5);//LittleDistrict
	LastVillage->setExitLocation(1, 3, 19, 4);//PrincessPrison
	LastVillage->setTreeLocation(8, 20);
	LastVillage->setHouseLocation(0, 3, 9); LastVillage->houseNum++;
	LastVillage->setHouseLocation(1, 17, 22); LastVillage->houseNum++;
	LastVillage->lTOP = LittleDistrict;
	LastVillage->lRIGHT = PrincessPrison;

	//VaultGuard
	VaultGuard->setExitLocation(0, 2, 12, 3); //forest
	VaultGuard->setExitLocation(1, 1, 10, 5); //vault
	VaultGuard->setEnemyLocation(8, 7, 1, 16);
	VaultGuard->setEnemyLocation(12, 15, 2, 8);
	VaultGuard->setEnemyLocation(1, 15, 1, 6);
	VaultGuard->lLEFT = GrandForest;
	VaultGuard->lBOTTOM = Vault;

	//Vault
	Vault->setExitLocation(0, 0, 10, 5); // vaultGuard
	Vault->setEnemyLocation(4, 7, 1, 6);
	Vault->setEnemyLocation(4, 10, 3, 10);
	Vault->setItemLocation(12, 12, 2);
	Vault->setLock(0, "You need a key to open these doors!", VaultGuard);
	Vault->lTOP = VaultGuard;

	//PrincessPrison
	PrincessPrison->setExitLocation(0, 2, 19, 4); //LastVillage
	PrincessPrison->setPortalLocation(12, 12);
	PrincessPrison->lLEFT = LastVillage;
}
void Location::setHouseLocation(int houseNum, int X, int Y) {
	houseLocation[houseNum][0] = X;
	houseLocation[houseNum][1] = Y;
}
void Location::setExitLocation(int exitNum, int wall, int howFarFromCorner, int widthOfExit){
	exitLocation[exitNum][0] = wall;
	exitLocation[exitNum][1] = howFarFromCorner;
	exitLocation[exitNum][2] = widthOfExit;
}
void Location::setTreeLocation(int X, int Y) {
	treeLocation.push_back({ X,Y });
}
void Location::setItemLocation(int X, int Y, int itemId) {
	itemLocation.push_back({ X,Y });
	item.insert(std::pair<vector<int>, int>(itemLocation.back(), itemId));
}
void Location::setPortalLocation(int yPos, int xPos) {
	portalLocation.push_back({ xPos,yPos });
}
void Location::setLock(int itemId, string text, Location* _toBack) {
	toBack = _toBack; itemToUnlock = itemId; unlockText = text;
}
void Location::pickItem(vector<vector<int>> itemLocation) {
	for (int i = 0; i < currentLocation->itemLocation.size();i++) {
	
		if (player->Ypos == itemLocation[i][0] && player->Xpos == itemLocation[i][1]) {
			int id = 0;
			for (auto it = idList.begin(); it != idList.end(); ++it) { //find ID of found item
				if (it->second == idList[item[{itemLocation[i][0], itemLocation[i][1]}]])
					id = it->first;
			}
			std::vector<int>::iterator it = std::find(
				player->eq.begin(), player->eq.end(), id); //search if item alreadyin it

			if (it == player->eq.end()) { //if it is not collect
				cout << "You found " << idList[id] << "!" << endl;
				player->eq.push_back(id);
			}
		}
	}
}
void Location::checkIfLeft(Location* lTop, Location* lBottom, Location* lLeft, Location* lRight) {
	if (player->Ypos == 0) {
		MAP->initilizeMap();
		player->Ypos = MAP_SIZE - 2;
		currentLocation = lTop;//TOP 
	}
	if (player->Ypos == MAP_SIZE - 1) { 
		MAP->initilizeMap();
		player->Ypos = 1;
		currentLocation = lBottom;//BOTTOM 
	}
	if (player->Xpos == 0) {
		MAP->initilizeMap();
		player->Xpos = MAP_SIZE - 2;
		currentLocation = lLeft;//LEFT 
	}
	if (player->Xpos == MAP_SIZE - 1) {
		MAP->initilizeMap();
		player->Xpos = 1;
		currentLocation = lRight;//RIGHT 
	}
}
void Location::renderLocation() {
	MAP->initilizeMap();
	initializeLocations();
	while (playing) {
		player->move(*player);
		currentLocation->checkIfLeft(currentLocation->lTOP, currentLocation->lBOTTOM, 
									 currentLocation->lLEFT, currentLocation->lRIGHT);
		MAP->refreshMap(*currentLocation);
	}
}
bool Location::requireItem(int id) { //checks if user has item with id "id"
	std::vector<int>::iterator it = std::find(
		player->eq.begin(), player->eq.end(), id);
	if (it == player->eq.end()) { //if it is not collect
		return false;
	}
	return true;
}

Location* currentLocation = new Location;

//INITILIZE LOCATIONS
Location* CrownCity = new Location;
Location* Road00 = new Location;

//GAME HARDCODE
Location* Spawn = new Location;
Location* CoastVillage = new Location;
Location* WitchHouse = new Location;
Location* Road01 = new Location;
Location* CareluanCity = new Location;
Location* KeyChamber = new Location;
Location* GrandForest = new Location;
Location* LittleDistrict = new Location;
Location* LastVillage = new Location;
Location* VaultGuard = new Location;
Location* Vault = new Location;
Location* PrincessPrison = new Location;
