#ifndef OBJECTWORLD_H
#define OBJECTWORLD_H
#include "ObjectScene.h"



class ObjectWorld : public ObjectScene
{

protected:
    glm::vec2 position_;

public:
    // 获取 position_
    glm::vec2 getPosition() const { return position_; }
    virtual void Update(float dt) override;
    // 设置 position_
    void setPosition(const glm::vec2 &pos);
    // 设置渲染坐标
    virtual void setRenderPosition(const glm::vec2 &rp) override;
};

#endif // OBJECT_WORLD_H