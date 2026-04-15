#include "GameScene.h"
#include "Cons.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"
#define BRICK_ROWS 3
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
    
    
    bool isPlaying = true;

    // DEBUG, SE PUEDE CAMBIAR DISEÑO LUEGO
    BinSave BINSAVE;    
    system("cls");
    std::string _name;
    std::cout << "\n\n\t::INSERT NICKNAME (6 Chars max)::" << std::endl;
    std::cin >> _name;
    //////


    while (isPlaying) {
        Sleep(FRAME_TIME);

        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Update();
        }
        Render();

        // Work In Progress
        if (gameManager->GameOver()) {
            cout << "\nYOU LOOOOOOSE!\n";
            // El juego se para todo el rato por esto:
            // Es solo para testear:
            isPlaying = false;
            cin.clear(); // CLEANS INPUT
            WaitForSpaceToContinue();
        }

    }

    system("cls");
    std::cout << "\n\n\tGUARDANDO PROGRESO..." << std::endl;

    // BINARIO KEEP
    WaitForSpaceToContinue();

    BINSAVE.username = _name;
    BINSAVE.points = gameManager->GetPoints();
    FileManager::BinSaveSys(BINSAVE); // CNTRL CLICK PARA REVISAR

    WaitForSpaceToContinue();
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