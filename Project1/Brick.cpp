#include "Brick.h"

Brick::Brick(Vector2 _pos, ConsoleColor c, GameManager* gm)
	: GameObject(_pos, '=', c) {
	destroyed = false;
	gameManager = gm;
}
bool Brick::GetDestroyed() const { return destroyed; }
void Brick::Destroy(unsigned short combo) {
	destroyed = true;
	if (gameManager == NULL) return;
	gameManager->AddPoints(POINTS_PER_BRICK + EXTRA_POINTS_PER_BRICK_COMBO * combo);
}

void Brick::Render() {
	GameObject::Render();
}