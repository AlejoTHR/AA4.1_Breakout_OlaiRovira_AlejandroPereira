#pragma once
class GameManager
{
private:
	unsigned int points;
	unsigned short lifes;

public:
	unsigned int GetPoints();
	void AddPoints(int pointsToAdd);
	unsigned short GetLifes();
	void LoseLife();
	GameManager();
	~GameManager();
};