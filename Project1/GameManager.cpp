#include "GameManager.h"
#include "Cons.h"
#include <vector>
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


void GameManager::Setnickname(BinSave &tmp, std::string &_name){
	tmp.nickName = _name;
}

std::string GameManager::Getnickname(BinSave &tmp, std::string _name){
	return tmp.nickName;
}

void GameManager::BinSaveSys(BinSave &SAVE, std::string Path) {

	BinSave tmp;

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::out | std::ios::app);
	if (!FileBin.is_open()) exit(15);

	// SAVING SYS ORDER = SAVE ALL DATA -> WRITE POINTS -> WRITE NAME
	tmp.pointsTotal = SAVE.pointsTotal;
	tmp.nickName = SAVE.nickName;

	// BIN POINTS
	FileBin.write(reinterpret_cast<char*>(&tmp.pointsTotal), sizeof(tmp.pointsTotal));

	// I HATE STRNGERS >:O
	// BIN STRNG
	// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
	short NameBinsize = tmp.nickName.size();
	// SAVE STRNG SIZE
	FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
	// SAVE STRNG CHAIN
	FileBin.write(tmp.nickName.c_str(), sizeof(char) * NameBinsize);
	
	FileBin << "\n";
	// FILE CLOSED
	FileBin.close();

	// FEEDBACK, EVERYTHING OK :D
	std::cout << "\t\t  SAVED" << std::endl << std::endl;
}

void GameManager::BinLoadingSys(std::string Path, std::vector<BinSave>& ALL_RANKINGS)
{
	std::cout << "Now Loading..." << std::endl << std::endl; // FEEDBACK

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::in);
	if (!FileBin.is_open()) exit(15);

	////// PLAYER DATA READING PROCESS::
	BinSave tmp;
	// READ POINTS
	FileBin.read(reinterpret_cast<char*>(&tmp.pointsTotal), sizeof(tmp.pointsTotal));
	short NameBinsize;
	// READ STRNG SIZE
	FileBin.read(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
	tmp.nickName.resize(NameBinsize);
	// STRNG SIZE RE-SIZE FOR LOADING
	FileBin.read(&tmp.nickName[0], sizeof(char) * NameBinsize);
	// LAST "END" CAHRACTER OF THE STRNG STRUCTURE
	tmp.nickName += '\0';
	// DEBUG
	//std::cout << tmp.pointsTotal << std::endl << tmp.nickName << std::endl;
	ALL_RANKINGS.push_back(tmp);

	FileBin.close();
	std::cout << "LOADED" << std::endl << std::endl;
}

// Constructor / Destructor

GameManager::GameManager()
{
	points = 0;
	lifes = INITIAL_LIFES;
	lost = false;
}

GameManager::~GameManager()
{

}