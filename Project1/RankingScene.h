#pragma once
#include <tuple>
#include "Scene.h"
#include "Cons.h"
#include "GameManager.h"

using namespace std;

class RankingScene : public Scene
{
private:
	GameManager gameManager;
	string menuText;
	vector<GameManager::BinSave> rankingRegisters;

public:
	void Start() override;

	void Render() override;

	void Update() override;

	// Constructor
	RankingScene();

	// Destructor
	~RankingScene();
};