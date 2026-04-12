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
    Vector2 startPos;
    
    // See if the player has lost a life.
    void CheckBottomTouched();
    // Error handling in case the ball escapes the game window.
    void CheckOutOfBounds();
    // Set the ball in its starting position again.
    void ResetPosition();
    // Check if the object is a brick, and break it.
    bool BreakIfBrick(GameObject* obj);
    // Checking if there's something to bounce, and calculating the movement.
    void Bounce(GameObject* other, bool brickDestroyed);

public:
    void Update() override;

    Ball(Vector2 newPosition, ConsoleColor newColor, std::vector<GameObject*>& gameObjects, GameManager* gm);
};