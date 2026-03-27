#pragma once

#include "Scene.h"

class MenuScene : public Scene
{
	virtual void  Start() {

	}
		
	 void  Render() {
		std::cout << "\n\tPrress 1 to continue" << std::endl;

	}
	

	 void  Update() override{
			
		bool exit = false;

		while (!exit) {
			Sleep(100);

			for (int i = 0; i < objects.size(); i++) {
				objects[i]->Update();
			}

			exit = GetAsyncKeyState('1');

			Render();

		}

		nextScene = SceneIndex::GAMEPLAY;

	}
};