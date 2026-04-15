#pragma once
#include "Scene.h"
#include "Cons.h"

using namespace std;

class CreditsScene : public Scene
{
private:
	string menuText;
	string extraText;

public:
	void Start() override;

	void Render() override;

	void Update() override;

	// Constructor
	CreditsScene();

	// Destructor
	~CreditsScene();
};