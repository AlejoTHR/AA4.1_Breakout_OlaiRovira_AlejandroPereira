#include "GameScene.h"
#include "Cons.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"
// Private Methods

void GameplayScene::CreateWalls(){
    for (int i = 0; i < MAP_SIZE; i++) {
        objects.push_back(new Wall(Vector2(i, 0), YELLOW, false));
        objects.push_back(new Wall(Vector2(i, MAP_SIZE - 1), YELLOW, true));

        if (i > 0 && i < MAP_SIZE - 1) {
            objects.push_back(new Wall(Vector2(0, i), YELLOW, false));
            objects.push_back(new Wall(Vector2(MAP_SIZE - 1, i), YELLOW, false));
        }
    }
}

void GameplayScene::CreateBricks(){
    for (int row = 1; row <= BRICK_ROWS; row++) {
        for (int col = 1; col < MAP_SIZE - 1; col++) {
            objects.push_back(new Brick(Vector2(col, row), CYAN, gameManager));
        }
    }
}

void GameplayScene::CreatePlayer() {
    objects.push_back(new Pad(playerSpawnPos, WHITE, 1, MAP_SIZE));
}

void GameplayScene::CreateBall() {
    objects.push_back(new Ball(playerSpawnPos + Vector2(0, -5), WHITE, objects, gameManager));
}

void GameplayScene::CleanCanvas()
{
    for (int i = 0; i < objects.size(); i++)
    {
        objects.pop_back();
    }
}

// Public Methods
void GameplayScene::Start() {
    GameplayScene::CreateWalls();
    GameplayScene::CreateBricks();
    GameplayScene::CreatePlayer();
    GameplayScene::CreateBall();
}



void GameplayScene::Render() {
    system("cls");
    ConsoleSetColor(WHITE, BLACK);
    ConsoleXY(0, 0);
    cout << "LIFES: " << gameManager->GetLifes() << endl;
    cout << "POINTS: " << gameManager->GetPoints() << endl;

    for (int i = 0; i < objects.size(); i++) {
        Brick* touchedBrick = dynamic_cast<Brick*>(objects[i]);
        if (touchedBrick != NULL && touchedBrick->GetDestroyed()) {
			objects.erase(objects.begin() + i);
            gameManager->BrickDestroyed();
            i--;
        }
        objects[i]->Render();
    }

    ConsoleXY(MAP_SIZE, MAP_SIZE);
}

void GameplayScene::Update() {

    gameManager->Resetgame(); // RESTART POINS N LIFES

    system("cls");
    string _name;
    do
    {
        cout << "\n\n\t::INSERT NICKNAME (" << CHAR_MAX << " Chars max)::" << endl;
        cin >> _name;
        system("cls");
    } while (_name.size() > CHAR_MAX);

    while (!gameManager->GetGameEnded()) {
        Sleep(FRAME_TIME);

        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Update();
        }
        Render();
    }

    // Round Feedback
    cout << "\n\n\n\n\tGAME OVER" << endl;
    cout << endl << "Press Space to continue..." << endl;
    WaitForSpaceToContinue();
    cout << endl << gameManager->ShowGameOverMsg() << endl;

    // BINARIO KEEP
    BinSave BINSAVE;
    BINSAVE.username = _name;
    BINSAVE.points = gameManager->GetPoints();
    
    bool scoreSaved = FileManager::BinSaveSys(BINSAVE);
    cout << endl << (scoreSaved ? "Score correctly saved!" : "There was an error while saving the score!") << endl;
    cout << endl << "Press Space to continue..." << endl;
    WaitForSpaceToContinue();

    RunEnded = true;
    CleanCanvas(); // RESETS THE GAME

    nextScene = Scene::RANKING;
}

// Constructor
GameplayScene::GameplayScene() {
    playerSpawnPos = Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4);
    gameManager = new GameManager(MAP_SIZE * BRICK_ROWS);
}

// Destructor
GameplayScene::~GameplayScene() {

}