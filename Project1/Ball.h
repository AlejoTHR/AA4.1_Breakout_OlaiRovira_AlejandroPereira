#pragma once
#include "GameObject.h"
#include "GameManager.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

#include <vector>

class Ball : public GameObject {
private:
    Vector2 direction;
    std::vector<GameObject*>* objects;
    unsigned short brickCombo;
    GameManager* gameManager;
    
    void CheckBottomTouched();
    bool BreakIfBrick(GameObject* obj);
    void Bounce(GameObject* other, bool brickDestroyed);

public:
    Ball(Vector2 newPosition, ConsoleColor newColor, std::vector<GameObject*>& gameObjects, GameManager* gm);

    void Update() override;
};