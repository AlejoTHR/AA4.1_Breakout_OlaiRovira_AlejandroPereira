#include <iostream>
#include "RankingScene.h"

using namespace std;

void RankingScene::Start() {

}

void RankingScene::Render() {
	system("cls");
}

void RankingScene::Update() {
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
RankingScene::RankingScene() {
	
}

// Destructor
RankingScene::~RankingScene() {

}