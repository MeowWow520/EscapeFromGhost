#include "core/Game.h"



int main()
{
    Game& gameInstance = Game::getInstance();
    gameInstance.Initialize("Escape Form Ghost", 1280, 720);
    gameInstance.Running();
    return 0;
}