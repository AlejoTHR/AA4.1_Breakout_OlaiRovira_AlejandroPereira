#include "Ball.h"

void Ball::BreakIfBrick(GameObject* obj) {
    Brick* brick = dynamic_cast<Brick*>(obj);
    if (brick == NULL) return;
    brick->Destroy();
}

void Ball::Bounce(GameObject* other) {
    Vector2 otherPosition = other->GetPosition();

    bool obstacleInX = position + Vector2(direction.x, 0) == otherPosition;
    bool obstacleInY = position + Vector2(0, direction.y) == otherPosition;

    bool bounceLeft = false;
	bool bounceRight = false;
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
            return;
        }
        else if (position + Vector2(direction.x, 0) == otherPosition + Vector2(1, 0) ||
            position + Vector2(0, direction.y) == otherPosition + Vector2(1, 0) ||
            position + direction == otherPosition + Vector2(1, 0)) {
            direction = Vector2(1, -1);
            return;
        }
    }

	bool bounced = false;
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
        BreakIfBrick(other);
        if (otherPosition.y == 14) std::cout << "DEFEAT";
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

        Bounce(currentObject);
    }
}