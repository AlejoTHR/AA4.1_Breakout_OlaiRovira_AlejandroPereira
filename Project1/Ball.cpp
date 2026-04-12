#include "Ball.h"
#include "InputManager.h"

void Ball::CheckBottomTouched() {
    if (position.y < MAP_SIZE - 2) return;
    gameManager->LoseLife();
}

bool Ball::BreakIfBrick(GameObject* obj) {
    Brick* brick = dynamic_cast<Brick*>(obj);
    if (brick == NULL) return false;
    brick->Destroy(brickCombo);
    brickCombo++;
    return true;
}

void Ball::Bounce(GameObject* other, bool brickDestroyed) {
    Vector2 otherPosition = other->GetPosition();
    bool bounced = false;

    // It's possible that it's touching a side of the pad,
    // and in that case, the bounce will be different:
    Pad* pad = dynamic_cast<Pad*>(other);
    if (pad != NULL) {
        // We check both sides of the pad and if we're there,
        // we apply the proper bounce:
        if (position + Vector2(direction.x, 0) == otherPosition + Vector2(-1, 0) ||
            position + Vector2(0, direction.y) == otherPosition + Vector2(-1, 0) ||
            position + direction == otherPosition + Vector2(-1, 0)) {
            direction = Vector2(-1, -1);
            bounced = true;
        }
        else if (position + Vector2(direction.x, 0) == otherPosition + Vector2(1, 0) ||
            position + Vector2(0, direction.y) == otherPosition + Vector2(1, 0) ||
            position + direction == otherPosition + Vector2(1, 0)) {
            direction = Vector2(1, -1);
            bounced = true;
        }
    }

    bool obstacleInX = position + Vector2(direction.x, 0) == otherPosition;
    bool obstacleInY = position + Vector2(0, direction.y) == otherPosition;

    if (obstacleInX) {
        direction.x *= -1;
        bounced = true;
    }
    if (obstacleInY) {
        direction.y *= -1;
        bounced = true;
    }
    if (!obstacleInX && !obstacleInY && position + direction == otherPosition) {
        direction *= -1;
        bounced = true;
    }

    if (bounced) {
        // If it bounced, and the checked object is a Pad, it means
        // It bounced on the pad, so we reset the combo:
        if (pad != NULL) brickCombo = 0;
        // If it's not the pad and we haven't destroyed a brick this frame:
        else if (!brickDestroyed) if (BreakIfBrick(other)) brickDestroyed = true;
    }
}

void Ball::Update() {
    position = position + direction;
    bool brickDestroyed = false;
    for (int i = 0; i < objects->size(); i++) {
        GameObject* currentObject = (*objects)[i];

        if (currentObject == this) {
            continue;
        }

        Bounce(currentObject, brickDestroyed);
    }

    CheckBottomTouched();
}

// Constructor

Ball::Ball(Vector2 newPosition, ConsoleColor newColor, std::vector<GameObject*>& gameObjects, GameManager* gm)
    : GameObject(newPosition, '@', newColor) {
    direction = Vector2(0, 1);
    objects = &gameObjects;
    brickCombo = 0;
    gameManager = gm;
}