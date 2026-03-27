#ifndef OBJECT_H
#define OBJECT_H
#include <SDL3/SDL.h>
#include "Game.h"


class Game;

class Object {

public:
    Object();
    virtual ~Object() = default;

    virtual void Initialize() { }
    virtual void handleEvents(SDL_Event& event) { }
    virtual void Update(float dt) { }
    virtual void Render() { }

protected:
    Game* gameInstance = Game::getInstance();
};

#endif //! OBJECT_H
