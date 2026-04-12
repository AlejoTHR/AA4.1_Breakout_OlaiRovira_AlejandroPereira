#include "GameManager.h"
#include "Cons.h"
#include <iostream>

unsigned int GameManager::GetPoints() {
	return points;
}

void GameManager::AddPoints(int pointsToAdd) {
	points += pointsToAdd;
}

unsigned short GameManager::GetLifes() {
	return lifes;
}

void GameManager::LoseLife() {
	lifes--;
}

GameManager::GameManager()
{
	points = 0;
	lifes = INITIAL_LIFES;
}

GameManager::~GameManager()
{
}