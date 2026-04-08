#include <iostream>
#include "CreditsScene.h"

using namespace std;

void CreditsScene::Start() {

}

void CreditsScene::Render() {
	system("cls");
}

void CreditsScene::Update() {
	bool exit = false;
	while (!exit) {
		Sleep(MENU_FRAME_TIME);
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->Update();
		}

		Render();
	}

	//nextScene = options[selectedOption].second;
}

// Constructor
CreditsScene::CreditsScene() {

}

// Destructor
CreditsScene::~CreditsScene() {

}