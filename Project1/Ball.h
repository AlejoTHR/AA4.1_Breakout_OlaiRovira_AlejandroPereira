#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

#include <vector>

class Ball : public GameObject {
private:
    Vector2 direction;
    std::vector<GameObject*>* objects;
    unsigned short brickCombo;
    
    void CheckBottomTouched();
    bool BreakIfBrick(GameObject* obj);
    void Bounce(GameObject* other, bool brickDestroyed);

public:
    Ball(Vector2 newPosition, ConsoleColor newColor, std::vector<GameObject*>& gameObjects)
        : GameObject(newPosition, '@', newColor) {
        direction = Vector2(0, 1);
        objects = &gameObjects;
        brickCombo = 0;
    }

    void Update() override;
};