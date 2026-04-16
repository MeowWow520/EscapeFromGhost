#ifndef OBJECTSCENE_H
#define OBJECTSCENE_H
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include "Object.h"



class ObjectScene : public Object
{
    
protected:
    // 物体相机渲染位置
    glm::vec2 renderPos_;

public:
    // 获取 renderPos_
    glm::vec2 getRenderPos() const { return renderPos_; }
    // 设置 renderPos_
    virtual void setRenderPosition(const glm::vec2 &rp);
};
#endif // OBJECTSCENE_H