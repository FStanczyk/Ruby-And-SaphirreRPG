#include<conio.h>
#include<iostream>
#include"Globals.h"
using namespace std;

std::map<int, string> idList{
	{0 , "Key" },
	{1 , "Saphirre"},
	{2 , "Ruby"},
	{3 , "UltraVision"},
};
void Player::move(Player& player) {
	char KEY;
	KEY = _getch();
	point[player.Ypos][player.Xpos] = basePoint;
	switch(KEY) {
	case 'w': { 
		if(player.Ypos>0 && 
			(point[player.Ypos - 1][player.Xpos] == basePoint)
			|| point[player.Ypos - 1][player.Xpos] == itemPoint)
			player.Ypos--; break; 
	}
	case 'a': { 
		if (player.Xpos > 0 && (point[player.Ypos][player.Xpos - 1] == basePoint
		   ||point[player.Ypos][player.Xpos - 1] == itemPoint))
			player.Xpos--; break; 
	}
	case 's': { 
		if (player.Ypos < MAP_SIZE-1 &&( point[player.Ypos + 1][player.Xpos] == basePoint
		   || point[player.Ypos + 1][player.Xpos] == itemPoint))
			player.Ypos++; break; 
	}
	case 'd': {
		if (player.Xpos < MAP_SIZE-1 && (point[player.Ypos][player.Xpos + 1] == basePoint
			|| point[player.Ypos][player.Xpos + 1] == itemPoint))
			player.Xpos++; break; 
	}
	}
	point[player.Ypos][player.Xpos] = " X ";
}
void Player::checkBag(Player* player) {
	for(int i = 0;i<eq.size();i++)
		cout << " | " << idList[eq[i]] << flush;
	cout << endl;
}
Player* player = new Player("jacek");
