#include "GameScene.h"
#include "Cons.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"
#define BRICK_ROWS 3
#define CHAR_MAX 10
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

    bool isPlaying = true;

    BinSave BINSAVE;    
    system("cls");

    std::string _name;
    do
    {
        std::cout << "\n\n\t::INSERT NICKNAME (10 Chars max)::" << std::endl;
        std::cin >> _name;
        system("cls");
    } while (_name.size() > CHAR_MAX);

        
    //////


    while (isPlaying) {
        Sleep(FRAME_TIME);

        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Update();
        }
        Render();

        // Work In Progress
        if (gameManager->GetGameEnded()) {
            cout << "\n\n\n\n\t\tGAME OVER\n" << endl << endl;
            cout << endl << "\t\t" << gameManager->ShowGameOverMsg();
            WaitForSpaceToContinue();

            isPlaying = false;
        }

    }

    system("cls");
    std::cout << "\n\n\tSAVING..." << std::endl;
    std::cout << "Press Space to continue...";
    WaitForSpaceToContinue();
    system("cls");

    // BINARIO KEEP
    BINSAVE.username = _name;
    BINSAVE.points = gameManager->GetPoints();
    
    FileManager::BinSaveSys(BINSAVE);
    std::cout << "Press Space to continue...";
    WaitForSpaceToContinue();

    RunEnded = true;
    CleanCanvas(); // RESETS THE GAME

    nextScene = Scene::RANKING;
    system("cls");
}

// Constructor
GameplayScene::GameplayScene() {
    playerSpawnPos = Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4);
    gameManager = new GameManager(MAP_SIZE * BRICK_ROWS);
}

// Destructor
GameplayScene::~GameplayScene() {

}