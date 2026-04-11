#pragma once
class GameManager
{
private:
	unsigned int points;
	unsigned short lifes;

public:
	void AddPoints(int pointsToAdd);
	unsigned short GetLifes();
	unsigned int GetPoints();
	GameManager();
	~GameManager();
};