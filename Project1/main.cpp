#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"

#include "Cons.h"
#include "Scene.h"
#include "MenuScene.h"
#include "GameScene.h"

#define MAP_SIZE 15


int main() {
    srand((unsigned int)time(NULL));
    
    Scene* AllSecenes[3];

    AllSecenes[Scene::MENU] = new MenuScene;
    AllSecenes[Scene::GAMEPLAY] = new GameplayScene;

    Scene::SceneIndex index = Scene::MENU;

    bool isExitTime = false;
    while (!isExitTime) 
    {
        AllSecenes[index]->Start();
        AllSecenes[index]->Update();

        index = AllSecenes[index]->ChangeScene();

    }


    //  std::vector<GameObject*> objects;
    //  
    //  Start(objects);
    //  Update(objects);

    return 0;
}
