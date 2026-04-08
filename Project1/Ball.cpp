#include "Ball.h"

bool Ball::IsCollidingWith(GameObject* other) {
    return position == other->GetPosition();
}

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

    }


}

void Ball::Update() {
    position.x = position.x + direction.x;
    position.y = position.y + direction.y;

    for (int i = 0; i < objects->size(); i++) {
        GameObject* currentObject = (*objects)[i];

        if (currentObject == this) {
            continue;
        }

        if (IsCollidingWith(currentObject)) {
            Bounce(currentObject);
            // https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
            Brick* touchedBrick = dynamic_cast<Brick*>(currentObject);
            if (touchedBrick != NULL) {
                touchedBrick->Destroy();
            }
            break;
        }
    }
}