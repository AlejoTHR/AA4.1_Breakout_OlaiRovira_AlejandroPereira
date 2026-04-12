#pragma once
#include "GameObject.h"
#include <Windows.h>

class Pad : public GameObject {
private:
    int width;
    int mapSize;

public:
    Pad(Vector2 newPosition, ConsoleColor newColor, int newWidth, int newMapSize);

    int GetWidth() const;

    void Update() override;
    void Render() override;
};