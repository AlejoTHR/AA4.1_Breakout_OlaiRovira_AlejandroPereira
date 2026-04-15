#pragma once
#include <string>
#include <vector>
#include <stack>
#include <fstream>

class GameManager
{
private:
	unsigned int points;
	short lifes;
	bool GameEnded;
	bool youWin = false;
	std::string gameOverMsng;

	unsigned int brickCounter;
public:

	unsigned int GetPoints();
	void AddPoints(int pointsToAdd);

	short GetLifes();
	void LoseLife();
	bool GetGameEnded();
	void Resetgame();

	std::string ShowGameOverMsg();

	void BrickDestroyed();
	// Constructor / Destructor
	GameManager(unsigned int _brickTotal);
	~GameManager();
};