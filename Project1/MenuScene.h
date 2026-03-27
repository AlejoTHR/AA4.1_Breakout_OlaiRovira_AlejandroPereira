#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
public:
	void Start() override;
		
	void Render() override;
	
	void Update() override;

	// Constructor
	MenuScene();

	// Destructor
	~MenuScene();
};