#pragma once
#include "GameObject.h"
#include "GameManager.h"

class Brick : public GameObject {
protected:
	bool destroyed;
	GameManager* gameManager;

public:
	bool GetDestroyed() const;
	void Destroy(unsigned short combo);

	void Render() override;

	Brick(Vector2 _pos, ConsoleColor c, GameManager* gm);
};