#pragma once
#include "Scene.h"
#include "MenuScene.h"

#define FRAME_TIME 150

class GameplayScene : public Scene {

protected:
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