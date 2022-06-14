#pragma once
#include "Globals.h"
#include<map>
#include<string>
using namespace std;
class Bag
{
public:
	std::map<int, string> idList{
		{0 , "Sword" },
		{1 , "Hat"}
	};
	vector<int> eq = { 1 };
	void checkBag(Player* p);
};

