#include <iostream>
#include "CreditsScene.h"

using namespace std;

void CreditsScene::Start() {

}

void CreditsScene::Render() {
	system("cls");
	cout << "\t ::CREDITS::" << endl << endl <<
		" - ALEJANDRO PEREIRA -" << endl <<
		" - OLAI ROVIRA -" << endl << endl <<
		"Press Space to continue..." << endl;
}

void CreditsScene::Update() {
	Sleep(MENU_FRAME_TIME);
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}

	Render();
	WaitForSpaceToContinue();
}

// Constructor
CreditsScene::CreditsScene() {
	nextScene = Scene::MENU;
}

// Destructor
CreditsScene::~CreditsScene() {

}