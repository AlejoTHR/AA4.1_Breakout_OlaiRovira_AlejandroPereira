#pragma once
#include <tuple>
#include "Scene.h"
#include "Cons.h"

using namespace std;

class RankingScene : public Scene
{
private:

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