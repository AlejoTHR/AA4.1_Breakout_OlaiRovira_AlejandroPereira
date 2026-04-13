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
		cout << endl << i + 1 << ") " << rankingRegisters[0].nickName << " ____________ " << rankingRegisters[0].pointsTotal << endl;
	}
	cout << endl << endl << "Press Space To Continue..." << endl;
	WaitForSpaceToContinue();
}

void RankingScene::Update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}
	// This scope is just used to erase "tempRankingRegisters" from memory after its usage:
	{
		// Read the saves file and put its info into an unsorted vector, which will be sorted later:
		vector<GameManager::BinSave> tempRankingRegisters;
		gameManager.BinLoadingSys("binsave.dat", tempRankingRegisters);
		// En vez de esta línea, se llamará a una función para ordenar:
		rankingRegisters = tempRankingRegisters;
	}
	Render();
}

// Constructor
RankingScene::RankingScene() {
	menuText = "\n\t::RANKINGS::";
	nextScene = Scene::MENU;
}

// Destructor
RankingScene::~RankingScene() {

}