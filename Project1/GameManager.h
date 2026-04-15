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
	bool over;

	unsigned int brickCounter;
public:

	unsigned int GetPoints();
	void AddPoints(int pointsToAdd);

	short GetLifes();
	void LoseLife();
	bool GameOver();

	void BrickDestroyed();

	// Constructor / Destructor
	GameManager(unsigned int _brickTotal);
	~GameManager();
};