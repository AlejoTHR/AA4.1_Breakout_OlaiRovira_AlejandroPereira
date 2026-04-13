#include <iostream>
#include "RankingScene.h"
#include "GameManager.h"

using namespace std;

void RankingScene::Start() {

}

void RankingScene::Render() {
	system("cls");
	GameManager::BinSave BINLOAD;
	std::vector<GameManager::BinSave> ALL_RANKING;
	gamemanager.BinLoadingSys(BINLOAD, "binsave.dat", ALL_RANKING);

	cout << endl << menuText << endl << "Press Space to continue..." << endl;
	WaitForSpaceToContinue();
	system("cls");

	GameManager::BinSave tmp;
	std::vector<GameManager::BinSave> TMPsort;

	for (size_t i = 0; i < ALL_RANKING.size(); i++)
	{

	}

	for (size_t i = 0; i < ALL_RANKING.size(); i++)
	{
		cout << std::endl << ALL_RANKING[0].nickName << " ____________ " << ALL_RANKING[0].pointsTotal << std::endl;
		Sleep(100);
	}
	WaitForSpaceToContinue();



}

void RankingScene::Update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update();
	}
	Render();
	WaitForSpaceToContinue();
}

// Constructor
RankingScene::RankingScene() {
	
	menuText = "\n\t::RANKINGS::";
	nextScene = Scene::MENU;
}

// Destructor
RankingScene::~RankingScene() {

}