#pragma once
#include "Scene.h"
#include "Cons.h"

using namespace std;

class CreditsScene : public Scene
{
private:

public:
	void Start() override;

	void Render() override;

	void Update() override;

	// Constructor
	CreditsScene();

	// Destructor
	~CreditsScene();
};