#include "core/Game.h"



int main(int argc, char *argv[])
{
    Game& gameInstance = Game::getInstance();
    gameInstance.Initialize("Escape Form Ghost", 1280, 720);
    gameInstance.Running(argc, argv);
    return 0;
}