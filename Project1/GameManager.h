#pragma once

class GameManager
{
private:
	unsigned int points;
	short lifes;
	bool lost;

public:
	unsigned int GetPoints();
	void AddPoints(int pointsToAdd);
	short GetLifes();
	void LoseLife();
	bool GameLost();
	GameManager();
	~GameManager();


};