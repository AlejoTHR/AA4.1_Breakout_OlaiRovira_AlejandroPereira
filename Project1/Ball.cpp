#include "Ball.h"

bool Ball::HasObjectAtPosition(int x, int y) {
    Vector2 targetPosition(x, y);

    for (int i = 0; i < objects->size(); i++) {
        if ((*objects)[i] == this) {
            continue;
        }

        if ((*objects)[i]->GetPosition() == targetPosition) {
            return true;
        }
    }

    return false;
}

void Ball::Bounce(GameObject* other) {
    Vector2 otherPosition = other->GetPosition();

    // It's possible that it's touching a side of the pad,
    // and in that case, the bounce will be different;
    Pad* pad = dynamic_cast<Pad*>(other);
    if (pad != NULL) {
        // We check both sides of the pad and if we're there,
        // we apply the proper bounce:
        if (position == pad->GetPosition() + Vector2(-1, 0)) {
            direction = Vector2(-1, -1);
            return;
        }
        else if (position == pad->GetPosition() + Vector2(1, 0)) {
            direction = Vector2(1, -1);
            return;
        }
    }

    bool obstacleInX = position + Vector2(0, direction.y) == other->GetPosition();
    bool obstacleInY = position + Vector2(direction.x, 0) == other->GetPosition();
    if (obstacleInX) {
        direction.y *= -1;
    }
    if (obstacleInY) {
        direction.x *= -1;
    }
    if (!obstacleInX && !obstacleInY && position + direction == other->GetPosition()) {
        direction *= -1;
    }

    /*
    bool hasObjectAbove = HasObjectAtPosition(otherPosition.x, otherPosition.y - 1);
    bool hasObjectBelow = HasObjectAtPosition(otherPosition.x, otherPosition.y + 1);
    bool hasObjectLeft = HasObjectAtPosition(otherPosition.x - 1, otherPosition.y);
    bool hasObjectRight = HasObjectAtPosition(otherPosition.x + 1, otherPosition.y);

    bool bounceHorizontal = hasObjectAbove || hasObjectBelow;
    bool bounceVertical = hasObjectLeft || hasObjectRight;

    if (!bounceHorizontal && !bounceVertical) {
        direction.x = -direction.x;
        direction.y = -direction.y;
        std::cout << bounceHorizontal << "|" << bounceVertical;

        return;
    }

    if (bounceHorizontal && bounceVertical) {
        direction.x = direction.x;
        direction.y = -direction.y;
        std::cout << bounceHorizontal << "|" << bounceVertical;

        return;
    }

    if (bounceVertical) {
        direction.y = -direction.y;
        std::cout << bounceHorizontal << "|" << bounceVertical;
    }

    if (bounceHorizontal) {

        direction.x = -direction.x;
        std::cout << bounceHorizontal << "|" << bounceVertical;
    }*/
}

void Ball::Update() {
    position.x = position.x + direction.x;
    position.y = position.y + direction.y;

    for (int i = 0; i < objects->size(); i++) {
        GameObject* currentObject = (*objects)[i];

        if (currentObject == this) {
            continue;
        }

        Bounce(currentObject);
    }
}