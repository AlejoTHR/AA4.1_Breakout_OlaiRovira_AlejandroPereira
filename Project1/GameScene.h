#pragma once
#include "Scene.h"
#include "MenuScene.h"
#include "GameManager.h"
#include "FileManager.h"

#define FRAME_TIME 150
#define BRICK_ROWS 3
#define CHAR_MAX 20

class GameplayScene : public Scene {
private:
    bool RunEnded = true;
    Vector2 playerSpawnPos;
    GameManager* gameManager;

    void CreateWalls();

    void CreateBricks();

    void CreatePlayer();

    void CreateBall();

    void CleanCanvas();

public:
    void Start() override;

    void Render() override;

    void Update() override;

    // Constructor
    GameplayScene();

    // Destructor
    ~GameplayScene();
};