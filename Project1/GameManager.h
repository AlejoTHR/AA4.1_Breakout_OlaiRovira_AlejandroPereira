#pragma once
#include <string>
#include <vector>
#include <stack>
#include <fstream>

class GameManager
{
public:
	struct BinSave {
		std::string nickName;
		unsigned int pointsTotal;
	};

private:
	unsigned int points;
	short lifes;
	bool lost;
	std::fstream FileBin;
	std::vector<BinSave> ALLRANKING;

public:
	unsigned int GetPoints();
	void AddPoints(int pointsToAdd);
	
	short GetLifes();
	void LoseLife();
	bool GameLost();

	void Setnickname(BinSave &tmp, std::string &_name);
	std::string Getnickname(BinSave &tmp, std::string _name);

	bool BinSaveSys(BinSave &tmp, std::string Path);
	bool BinLoadingSys(std::string Path, std::vector<BinSave> &ALL_RANKINGS);

	// Constructor / Destructor
	GameManager();
	~GameManager();
};