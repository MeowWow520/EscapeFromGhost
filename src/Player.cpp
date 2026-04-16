#include "Player.h"



void Player::Initialize()
{
    maxSpeed_ = 500.00f;
}



void Player::HandleEvents(SDL_Event &event)
{
    (void)event;
}

void Player::Update(float dt)
{
    keyboardControl();
    velocity_ *= 0.9f;
    Move(dt);
    syncCamera();
}

void Player::Render()
{
    gameInstance_.drawBoundary(renderPos_, renderPos_ + glm::vec2(20.0f), 5.0f, {1.0, 0.0, 0.0, 1.0});
}

void Player::Clean()
{
}

void Player::keyboardControl()
{
    auto currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W]) velocity_.y = -maxSpeed_;
    if (currentKeyStates[SDL_SCANCODE_S]) velocity_.y = +maxSpeed_;
    if (currentKeyStates[SDL_SCANCODE_A]) velocity_.x = -maxSpeed_;
    if (currentKeyStates[SDL_SCANCODE_D]) velocity_.x = +maxSpeed_;
}

void Player::Move(float dt)
{
    setPosition(position_ + velocity_ * dt);
    SDL_Log("dt: %f, position: (%f, %f), velocity: (%f, %f)",
        dt, position_.x, position_.y, velocity_.x, velocity_.y
    );
    // FIXME: 没有与参数列表匹配的 重载函数 "glm::clamp" 实例C/C++(304)
    // FIXME: 不允许使用指向不完整类型 "Scene" 的指针或引用C/C++(833)
    position_ = glm::clamp(position_, glm::vec2(0), gameInstance_.getCurrentScene()->getWorldSize());
}

void Player::syncCamera()
{
    // FIXME: 不允许使用指向不完整类型 "Scene" 的指针或引用C/C++(833)
    // FIXME: 类 "Game" 没有成员 "getScreenSize"C/C++(135)
    gameInstance_.getCurrentScene()->setCameraPosition(position_ - gameInstance_.getScreenSize() / 2.0f);
}
