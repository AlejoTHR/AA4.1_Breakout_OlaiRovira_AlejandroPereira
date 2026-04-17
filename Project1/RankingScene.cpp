#include <iostream>
#include "RankingScene.h"
#include "GameManager.h"

using namespace std;

void RankingScene::Start() {

}

void RankingScene::Render() {
	system("cls");
	cout << menuText << endl << endl;
	for (size_t i = 0; i < rankingRegisters.size(); i++)
	{
		cout << endl << i + 1 << ") " << rankingRegisters[i].username << " ____________ " << rankingRegisters[i].points << endl;
	}
	if (rankingRegisters.size() <= 0) cout << "There are no player saved!";
	cout << endl << endl << extraText << endl;
	WaitForSpaceToContinue();
}

void RankingScene::Update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}
	FileManager::BinLoadingSys(rankingRegisters);
	Render();
}

// Constructor
RankingScene::RankingScene() {
	menuText = R"( ____         _        _     _      _    __      _____
|  _ \       / \      | \   | |    | |  / /    / ____|
| |_) |     / _ \     |  \  | |    | | / /    | (___
|  _ <     / ___ \    |   \ | |    | |< <      \___ \
|_| \_\   /_/   \_\   |    \| |    |_| \_\     ____) |)";
	extraText = "Press Space To Continue...";
	nextScene = Scene::MENU;
}

// Destructor
RankingScene::~RankingScene() {

}