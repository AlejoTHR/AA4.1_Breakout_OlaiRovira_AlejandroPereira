#pragma once
#include "Scene.h"
#include "MenuScene.h"
#include "GameManager.h"

#define FRAME_TIME 150

class GameplayScene : public Scene {
private:
    Vector2 playerSpawnPos;
    GameManager* gameManager;

    void CreateWalls();

    void CreateBricks();

    void CreatePlayer();

    void CreateBall();

public:
    void Start() override;

    void Render() override;

    void Update() override;

    // Constructor
    GameplayScene();

    // Destructor
    ~GameplayScene();
};