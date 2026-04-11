#include "GameObject.h"

void GameObject::Render()
{
	ConsoleSetColor(color, BLACK);
	ConsoleXY(position.x, position.y + GAME_WINDOW_Y_OFFSET);
	std::cout << charToPrint;
}
