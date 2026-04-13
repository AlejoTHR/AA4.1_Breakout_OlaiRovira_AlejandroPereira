#include <iostream>
#include "RankingScene.h"
#include "GameManager.h"

using namespace std;

void RankingScene::Start() {

}

void RankingScene::Render() {
	system("cls");
	GameManager::BinSave BINLOAD;

	gamemanager.BinLoadingSys(BINLOAD, "binsave.dat");

	cout << endl << menuText << endl << endl <<
		"hacer sistema de lectura de binario" << endl << endl <<
		"Press Space to continue..." << endl;

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
	
	menuText = "\t ::RANKINGS::";
	nextScene = Scene::MENU;
}

// Destructor
RankingScene::~RankingScene() {

}