#include "MenuScene.h"

#include <iostream>

using namespace std;

void MenuScene::Start() {

}

void MenuScene::Render() {
	cout << "\n\tPrress 1 to continue" << endl;
}

void MenuScene::Update() {
	bool exit = false;

	while (!exit) {
		Sleep(100);

		for (int i = 0; i < objects.size(); i++) {
			objects[i]->Update();
		}

		exit = GetAsyncKeyState('1');

		Render();
	}

	nextScene = SceneIndex::GAMEPLAY;
}

// Constructor
MenuScene::MenuScene() {

}

// Destructor
MenuScene::~MenuScene() {

}