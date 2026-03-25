#include "core/Game.h"



int main(int argc, char** argv)
{
    Game& game = Game::getInstance();
    game.Initialize("Escape Form Ghost", 1280, 720);
    game.Running(argc, argv);
    return 0;
}