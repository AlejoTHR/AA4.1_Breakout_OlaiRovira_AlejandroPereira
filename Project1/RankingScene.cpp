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
	// This scope is just used to erase "tempRankingRegisters" from memory after its usage:
	{
		// Read the saves file and put its info into an unsorted vector, which will be sorted later:
		vector<BinSave> tempRankingRegisters;
		FileManager::BinLoadingSys(tempRankingRegisters);
		// En vez de esta línea, se llamará a una función para ordenar:
		rankingRegisters = FileManager::SortLoadedPoints(tempRankingRegisters);
	}
	Render();
}

// Constructor
RankingScene::RankingScene() {
	menuText = "\n\t::RANKINGS::";
	extraText = "Press Space To Continue...";
	nextScene = Scene::MENU;
}

// Destructor
RankingScene::~RankingScene() {

}