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
	GameEnded = lifes <= 0;
}

bool GameManager::GetGameEnded() {
	return GameEnded;
}

void GameManager::Resetgame()
{
	lifes = 3;
	points = 0;
	GameEnded = false;
}
#pragma endregion

std::string GameManager::ShowGameOverMsg()
{
	return (youWin) ? "\tYOU WIN" : "\tYOU LOOSE";
}


void GameManager::BrickDestroyed()
{
	brickCounter--;
	std::cout << "X";
	if (brickCounter <= 0)
	{
		youWin = true;
		GameEnded = true;
	}
}

// Constructor / Destructor

GameManager::GameManager(unsigned int _brickTotal)
{
	points = 0;
	lifes = INITIAL_LIFES;
	GameEnded = false;

	brickCounter = _brickTotal;
}

GameManager::~GameManager()
{

}