#include "GameManager.h"
#include "Cons.h"

void GameManager::AddPoints(int pointsToAdd) {
	points += pointsToAdd;
}

unsigned short GameManager::GetLifes() {
	return lifes;
}

unsigned int GameManager::GetPoints() {
	return points;
}

GameManager::GameManager()
{
	points = 0;
	lifes = INITIAL_LIFES;
}

GameManager::~GameManager()
{
}