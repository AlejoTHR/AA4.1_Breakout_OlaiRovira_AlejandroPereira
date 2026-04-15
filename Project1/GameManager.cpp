#include "GameManager.h"
#include "Cons.h"
#include <vector>
#include <stack>
#include <iostream>


#pragma region GAME STATE

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
	over = lifes <= 0;
}

bool GameManager::GameOver() {
	return over;
}
#pragma endregion

void GameManager::BrickDestroyed()
{
	brickCounter--;
}

// Constructor / Destructor

GameManager::GameManager(unsigned int _brickTotal)
{
	points = 0;
	lifes = INITIAL_LIFES;
	over = false;

	brickCounter = _brickTotal;
}

GameManager::~GameManager()
{

}