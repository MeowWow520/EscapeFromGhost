#include "objectWorld.h"
#include "Scene.h"



void ObjectWorld::Update(float dt)
{
    ObjectScene::Update(dt);
    renderPos_ = gameInstance_.getCurrentScene()->worldToScreen(position_);
}

void ObjectWorld::setPosition(const glm::vec2 &pos)
{
    position_ = pos;
    renderPos_ = gameInstance_.getCurrentScene()->worldToScreen(position_);
}

void ObjectWorld::setRenderPosition(const glm::vec2 &rp)
{
    renderPos_ = rp;
    position_ = gameInstance_.getCurrentScene()->screenToWorld(rp);
}