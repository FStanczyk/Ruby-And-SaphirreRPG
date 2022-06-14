#pragma once
#include "Map.h"
#include "Location.h"
#include "Map.h"
#include "Player.h"
#include"Enemy.h"
#include<map>
using namespace std;
extern bool playing;
extern std::map<int, string> idList;
extern Location* currentLocation;
extern Player* player;
extern Location* CrownCity;
extern Location* Road00;
extern Map* MAP;
extern Location* Spawn;
extern Location* CoastVillage;
extern Location* WitchHouse;
extern Location* Road01;
extern Location* CareluanCity;
extern Location* KeyChamber;
extern Location* GrandForest;
extern Location* LittleDistrict;
extern Location* LastVillage;
extern Location* VaultGuard;
extern Location* Vault;
extern Location* PrincessPrison;
extern void displayText(string text, bool _continue);
extern void initializeLocations();


