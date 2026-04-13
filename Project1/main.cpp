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
#include "RankingScene.h"
#include "CreditsScene.h"

#define MAP_SIZE 15


int main() {
    srand((unsigned int)time(NULL));
    
    Scene* AllSecenes[SCENES_NUM];

    AllSecenes[Scene::MENU] = new MenuScene;
    AllSecenes[Scene::GAMEPLAY] = new GameplayScene;
    AllSecenes[Scene::RANKING] = new RankingScene;
    AllSecenes[Scene::CREDITS] = new CreditsScene;

    Scene::SceneIndex index = Scene::MENU;

    bool isExitTime = false;
    while (!isExitTime) 
    {
        AllSecenes[index]->Start();
        AllSecenes[index]->Update();

        index = AllSecenes[index]->ChangeScene();
        if (index == Scene::EXIT) isExitTime = true;

        // The only purpose of this is giving time for the player to release
        // any pressed button so the next scene doesn't read an unwanted input:
        system("cls");
        cout << "Loading...";
        Sleep(SCENE_TRAVEL_TIME);
    }

    system("cls");
    cout << "Goodbye!" << endl;
    return 0;
}
