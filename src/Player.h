#ifndef PLAYER_H
#define PLAYER_H
#include <glm/glm.hpp>
#include "core/Actor.h"


class Player : public Actor 
{
    
public:
    virtual void Initialize() override;
    virtual void HandleEvents(SDL_Event& event) override;
    virtual void Update(float dt) override;
    virtual void Render() override;
    virtual void Clean() override;

    void keyboardControl();
    void Move(float dt);
    void syncCamera();

};
#endif // PLAYER_H