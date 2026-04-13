#include "GameManager.h"
#include "Cons.h"
#include <vector>
#include <iostream>

// GAME STATE

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

//  

void GameManager::Setnickname(BinSave &tmp, std::string &_name){
	tmp.nickName = _name;
}

std::string GameManager::Getnickname(BinSave &tmp, std::string _name){
	return tmp.nickName;
}

bool GameManager::BinSaveSys(BinSave &SAVE, std::string Path) {
	std::vector<BinSave> actualSavesFile;
	BinLoadingSys(SAVES_FILE, actualSavesFile);
	actualSavesFile.push_back(SAVE);

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::out);
	if (!FileBin.is_open()) {
		return false;
	}

	// SAVING SYS ORDER = SAVE NUM OF PLAYERS REGISTERED -> (WRITE POINTS -> WRITE NAME --> REPEAT)

	// Write number of registered players:
	short registeredPlayersNum = actualSavesFile.size();
	FileBin.write(reinterpret_cast<char*>(&registeredPlayersNum), sizeof(registeredPlayersNum));

	for (short i = 0; i < actualSavesFile.size(); i++)
	{
		// BIN POINTS
		FileBin.write(reinterpret_cast<char*>(&actualSavesFile[i].pointsTotal), sizeof(actualSavesFile[i].pointsTotal));
		// BIN STRNG
		// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
		short NameBinsize = actualSavesFile[i].nickName.size();
		// SAVE STRNG SIZE
		FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
		// SAVE STRNG CHAIN
		FileBin.write(actualSavesFile[i].nickName.c_str(), sizeof(char) * NameBinsize);
	}
	
	// FILE CLOSED
	FileBin.close();

	// FEEDBACK, EVERYTHING OK :D
	std::cout << "\t\t  SAVED" << std::endl << std::endl;
	return true;
}

bool GameManager::BinLoadingSys(std::string Path, std::vector<BinSave>& ALL_RANKINGS) {
	std::cout << "Now Loading..." << std::endl << std::endl; // FEEDBACK

	std::fstream FileBin;
	FileBin.open(Path, std::ios::binary | std::ios::in);
	if (!FileBin.is_open()) {
		return false;
	}

	// Read number of registered players:
	short registeredPlayersNum;
	FileBin.read(reinterpret_cast<char*>(&registeredPlayersNum), sizeof(short));

	for (short i = 0; i < registeredPlayersNum; i++)
	{
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
		ALL_RANKINGS.push_back(tmp);
	}
	
	FileBin.close();
	std::cout << "LOADED" << std::endl << std::endl;
	return true;
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