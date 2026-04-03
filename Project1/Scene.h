#pragma once
#include <vector>
#include "GameObject.h"
#include "InputManager.h"

class Scene {
public:
	enum SceneIndex { MENU, GAMEPLAY, RANKING, CREDITS, EXIT };

protected:
	std::vector<GameObject*> objects;
	SceneIndex nextScene;

public:
	virtual void Start() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;

	SceneIndex ChangeScene()
	{
		return nextScene;
	}

	// Constructor
	Scene() {
		nextScene = GAMEPLAY;
	}

	// Destructor
	~Scene() {

	}
};