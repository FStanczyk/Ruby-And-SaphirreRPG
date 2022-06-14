#include <iostream>
#include <string>
#include"Globals.h"
#include<windows.h>

using namespace std;
int letterTime = 8;
void displayText(string text, bool _continue){
	system("cls");
	int space = 1;
	for (auto i : text) {
		cout << i << flush;
		Sleep(letterTime);
		if (i == space * MAP_SIZE) {
			cout << endl;
			space++;
		}
	}
	Sleep(1000);
	if (_continue == true) {
		cout << endl;
		system("pause");
	}
}

void INTRO() {
	string name = "_";
	displayText("Welcome to the Chamber Of the Keys! Your task is to open portal with use of ruby and Saphirre",true);
	displayText("My name is Josh, I will try to help you with your voyage.", false);
	displayText("But first... what is your name?", false);
	cout << endl;
	cout << "Put your name" << endl;
	cin >> name;
	player->name = name;
	displayText(name+" wow! Such a beautifull name! I've never heard about it in these regions...",  true);
	displayText("Okay, we don't have to much time, first you need to know are the enemies.", true);
	displayText("@ are your enemies, each one looks only at one direction (N,S,W,E) and have some line of sight(LoS)", true);
	displayText("When you enter theirs LoS... you die. Try to remember their LoS and avoid at all cost.", true);
	displayText("Pick the items '#' simply by going on top of them. You can't really use them but you will surely know if having one is needed.", true);
	displayText("I think you are ready to start the journey! Good Luck", true);

}
bool playing = false;
int main() {
	if (!playing) {
		playing = true;
		INTRO();
		currentLocation = Spawn;
		while (playing) {
			currentLocation->renderLocation();
		}
	}
	system("cls");
	cout << "GAME OVER" << endl;
}
