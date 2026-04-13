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

	BinSave tmp;

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::out);
	if (!FileBin.is_open()) exit(15);

	// SAVING SYS ORDER = SAVE ALL DATA -> WRITE POINTS -> WRITE NAME
	tmp.pointsTotal = SAVE.pointsTotal;
	tmp.nickName = SAVE.nickName;

	// BIN POINTS
	FileBin.write(reinterpret_cast<char*>(&tmp.pointsTotal), sizeof(tmp.pointsTotal));

	// I HATE STRNGERS >:O
	// BIN STRNG
	// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
	size_t NameBinsize = tmp.nickName.size();
	// SAVE STRNG SIZE
	FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(size_t));
	// SAVE STRNG CHAIN
	FileBin.write(tmp.nickName.c_str(), sizeof(char) * NameBinsize);
	
	// FILE CLOSED
	FileBin.close();

	// FEEDBACK, EVERYTHING OK :D
	std::cout << "SAVED" << std::endl << std::endl;
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