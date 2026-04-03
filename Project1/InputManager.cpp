#include <windows.h>
#include <thread>
#include <chrono>
#include "Vector2.h"
#include "Cons.h"

using namespace std;

Vector2 GetPlayerDirection() {
	Vector2 direction;
	if (GetAsyncKeyState('A')) direction.x--;
	if (GetAsyncKeyState('D')) direction.x++;
	if (GetAsyncKeyState('W')) direction.y--;
	if (GetAsyncKeyState('S')) direction.y++;
	return direction;
}

bool PlayerInteracted() {
	return GetAsyncKeyState(VK_SPACE);
}

bool EscapePressed() {
	return GetAsyncKeyState(VK_ESCAPE);
}

void WaitForSpaceToContinue() {
	bool spacePressed = false;
	while (!spacePressed)
	{
		spacePressed = PlayerInteracted();
		this_thread::sleep_for(chrono::milliseconds(MENU_FRAME_TIME));
	}
}