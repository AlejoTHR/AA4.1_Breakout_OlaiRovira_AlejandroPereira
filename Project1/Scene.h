#pragma once
#include <vector>
#include "GameObject.h"

class Scene {
public:
	enum SceneIndex { MENU, GAMEPLAY, RANKING };

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