#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include "Object.h"



class Scene: public Object {

    glm::vec2 cameraPosition_;
    std::vector<Object*> objects_;
    
protected:
    glm::vec2 worldSize_;

public:
    // 坐标转换
    glm::vec2 worldToScreen(const glm::vec2 &world_position) const {
        return world_position - cameraPosition_;
    }
    glm::vec2 screenToWorld(const glm::vec2 &screen_position) const {
        return screen_position + cameraPosition_;
    }
    Scene() = default;
    virtual ~Scene() = default;

    virtual void Initialize() override { }
    virtual void HandleEvents([[maybe_unused]] SDL_Event& event) override { }
    virtual void Update([[maybe_unused]] float dt) override { }
    virtual void Render() override { }
    virtual void Clean() override { }
};



#endif // SCENE_H