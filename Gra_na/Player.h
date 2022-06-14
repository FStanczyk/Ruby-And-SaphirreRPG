#pragma once
#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

extern const int MAP_SIZE;
extern const string basePoint;
extern const string itemPoint;
extern string point[26][26];


class Player
{
public:

	string name = "Jacek Kucharz";
	int power = 5;
	int health = 100;

	int Xpos = 1;
	int Ypos = 1;

	string oldPoint = point[0][0];
	string weapon = "hand";
	Player(string name):name(name){};
	void move(Player& player);

	//EQ MANAGING
	vector<int> eq = {};
	void checkBag(Player* player);


};

