#pragma once
#include <tuple>
#include "Scene.h"
#include "Cons.h"
#include "FileManager.h"

using namespace std;

class RankingScene : public Scene
{
private:
	string menuText;
	string extraText;
	vector<BinSave> rankingRegisters;

public:
	void Start() override;

	void Render() override;

	void Update() override;

	// Constructor
	RankingScene();

	// Destructor
	~RankingScene();
};