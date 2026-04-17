#pragma once
#include "GameObject.h"

class Wall : public GameObject {
public:
	Wall(Vector2 pos, ConsoleColor c)
		: GameObject(pos, '#', c) {}
};

