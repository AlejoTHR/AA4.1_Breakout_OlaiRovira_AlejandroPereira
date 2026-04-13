#include "GameManager.h"
#include "Cons.h"
#include <iostream>

unsigned int GameManager::GetPoints() {
	return points;
}

void GameManager::AddPoints(int pointsToAdd) {
	points += pointsToAdd;
}

short GameManager::GetLifes() {
	return lifes;
}

void GameManager::LoseLife() {
	lifes--;
	lost = lifes <= 0;
}

bool GameManager::GameLost() {
	return lost;
}


void GameManager::Setnickname(BinSave tmp, std::string &_name){
	tmp.nickName = _name;
}

std::string GameManager::Getnickname(BinSave tmp, std::string _name){
	return tmp.nickName;
}

void GameManager::BinSaveSys(BinSave SAVE, std::string Path) {
	system("cls");
	std::cout << "\n\n\tGUARDANDO PROGRESO..." << std::endl;

	BinSave tmp;

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::out);
	if (!FileBin.is_open()) exit(15);


	tmp.nickName = SAVE.nickName;
	tmp.pointsTotal = SAVE.pointsTotal;



	system("pause");
}


GameManager::GameManager()
{
	points = 0;
	lifes = INITIAL_LIFES;
	lost = false;
}

GameManager::~GameManager()
{
}