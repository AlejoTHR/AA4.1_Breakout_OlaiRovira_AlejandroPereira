#include "GameManager.h"
#include "Cons.h"
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

GameManager::GameManager()
{
	points = 0;
	lifes = INITIAL_LIFES;
	lost = false;
}

GameManager::~GameManager()
{
}