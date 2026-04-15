#include <iostream>
#include "CreditsScene.h"

using namespace std;

void CreditsScene::Start() {

}

void CreditsScene::Render() {
	system("cls");
	cout << menuText << endl << endl <<
		" - ALEJANDRO PEREIRA -" << endl <<
		" - OLAI ROVIRA -" << endl << endl <<
		extraText << endl;
}

void CreditsScene::Update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}
	Render();
	WaitForSpaceToContinue();
}

// Constructor
CreditsScene::CreditsScene() {
	nextScene = Scene::MENU;
	menuText = "\t ::CREDITS::";
	extraText = "Press Space to continue...";
}

// Destructor
CreditsScene::~CreditsScene() {

}