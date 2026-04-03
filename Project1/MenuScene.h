#pragma once
#include <tuple>
#include "Scene.h"
#include "Cons.h"

using namespace std;

class MenuScene : public Scene
{
private:
	vector<pair<string, SceneIndex>> options;
	string menuText;
	string extraText;

	short selectedOption = 0; // Not unsigned to detect when the player goes below 0 to loop back up.
	unsigned long actualFrame = 0;
	Vector2 direction; // Where the player is moving the cursor.

public:
	void Start() override;
		
	void Render() override;
	
	void Update() override;

	// Constructor
	MenuScene();

	// Destructor
	~MenuScene();
};