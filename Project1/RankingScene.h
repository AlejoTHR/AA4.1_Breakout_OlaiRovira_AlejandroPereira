#pragma once
#include <tuple>
#include "Scene.h"
#include "Cons.h"
#include "GameManager.h"

using namespace std;

class RankingScene : public Scene
{
private:
	GameManager gamemanager;
protected:
	string menuText;
public:
	void Start() override;

	void Render() override;

	void Update() override;

	// Constructor
	RankingScene();

	// Destructor
	~RankingScene();
};