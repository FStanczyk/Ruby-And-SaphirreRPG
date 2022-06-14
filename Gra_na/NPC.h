#pragma once
#include <string>
using namespace std;
class NPC
{
public:
	int yPos = 0, xPos = 0;
	string text = "_";
	NPC(int yPos, int xPos, string text) :yPos(yPos), xPos(xPos), text(text){};
};

