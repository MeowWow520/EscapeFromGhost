#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <glm/glm.hpp>
#include "Object.h"



class Scene: public Object {

protected:
    // 相机位置属性, 用于视口移动和世界坐标转换
    glm::vec2 cameraPosition_ = glm::vec2(0);
    // 场景中的物体
    std::vector<Object*> objects_;

public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void Initialize() override { }
    virtual void handleEvents(SDL_Event& event) override { }
    virtual void Update(float dt) override { }
    virtual void Render() override { }
    virtual void Clean() override { }
};

#endif // SCENE_H