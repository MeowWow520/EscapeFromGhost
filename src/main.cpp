#include "core/Game.h"



int main(int argc, char *argv[])
{
    Game& gameInstance = Game::getInstance();
    gameInstance.Initialize();
    gameInstance.Running(argc, argv);
    gameInstance.Clean();
    return 0;
}