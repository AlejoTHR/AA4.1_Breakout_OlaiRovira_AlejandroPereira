#include <iostream>
#include "MenuScene.h"

using namespace std;

void MenuScene::Start() {

}

void MenuScene::Render() {
	system("cls");
	cout << endl << menuText << endl << endl;
	// We print each possible option one by one using the provided "options" list.
	for (int optionNum = 0; optionNum < options.size(); optionNum++)
	{
		// The selected option marker will only appear in case this option's num is the selected one,
		// and if the actual render frame is odd so that it flickers, but not if the player has just moved the cursor.
		bool canShowSelectionMarker = optionNum == selectedOption && ((actualFrame % 2 || direction.y != 0) || direction.x != 0);

		// Showing the available options with their list number:
		cout << optionNum + 1 << (optionNum == selectedOption ? (canShowSelectionMarker ? ". < " : ".   ") : ". ") << options[optionNum].first;
		// Showing non-multiple-choice selection marker (for when this option is selected but not triggered):
		if (canShowSelectionMarker) cout << " >";
		cout << endl;
	}
	if (!extraText.empty()) cout << endl << extraText;
}

void MenuScene::Update() {
	bool exit = false;
	while (!exit) {
		Sleep(MENU_FRAME_TIME);
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->Update();		
		}actualFrame++;

		// We need to know if the player has selected an option:
		exit = PlayerInteracted();

		// To know the way the player is navigating the menu, we get the input in the same way as in the game.
		direction = GetPlayerDirection();
		selectedOption += direction.y;
		// We want the selection to loop back if the player tries to move out of bounds from the last or first option.
		if (selectedOption < 0)
			selectedOption = options.size() - 1;
		if (selectedOption >= options.size())
			selectedOption = 0;

		Render();
	}

	nextScene = SceneIndex::GAMEPLAY;
}

// Constructor
MenuScene::MenuScene() {
	options = { {"PLAY", GAMEPLAY}, {"RANKING", RANKING}, {"CREDITS", CREDITS}, {"EXIT", EXIT}};
	menuText = "   ARKANOID";
	extraText = "  Move with W & S, select with SPACE.";
}

// Destructor
MenuScene::~MenuScene() {

}