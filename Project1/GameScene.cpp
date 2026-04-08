#include "GameScene.h"
#include "Cons.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"

// Private Methods

void GameplayScene::CreateWalls(){
    for (int i = 0; i < MAP_SIZE; i++) {
        objects.push_back(new Wall(Vector2(i, 0), YELLOW, false));
        objects.push_back(new Wall(Vector2(i, MAP_SIZE - 1), YELLOW, true));

        if (i > 0 && i < MAP_SIZE - 1) {
            objects.push_back(new Wall(Vector2(0, i), YELLOW, false));
            objects.push_back(new Wall(Vector2(MAP_SIZE - 1, i), YELLOW, false));
        }
    }
}

void GameplayScene::CreateBricks(){
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col < MAP_SIZE - 1; col++) {
            objects.push_back(new Brick(Vector2(col, row), CYAN));
        }
    }
}

void GameplayScene::CreatePlayer() {
    objects.push_back(new Pad(Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4), WHITE, 1, MAP_SIZE));
}

void GameplayScene::CreateBall() {
    objects.push_back(new Ball(Vector2(2, MAP_SIZE / 2), WHITE, objects));
}

// Public Methods

void GameplayScene::Start() {
    GameplayScene::CreateWalls();
    GameplayScene::CreateBricks();
    GameplayScene::CreatePlayer();
    GameplayScene::CreateBall();
}

void GameplayScene::Render() {
    system("cls");
    ConsoleSetColor(WHITE, BLACK);

    for (int i = 0; i < objects.size(); i++) {
        Brick* touchedBrick = dynamic_cast<Brick*>(objects[i]);
        if (touchedBrick != NULL && touchedBrick->GetDestroyed()) {
			objects.erase(objects.begin() + i);
            i--;
        }
        objects[i]->Render();
    }

    ConsoleXY(MAP_SIZE, MAP_SIZE);
}

void GameplayScene::Update() {
    bool isPlaying = true;

    while (isPlaying) {
        Sleep(FRAME_TIME);

        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Update();
        }

        Render();
    }
}

// Constructor
GameplayScene::GameplayScene() {

}

// Destructor
GameplayScene::~GameplayScene() {

}