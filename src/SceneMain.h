#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include "core/Scene.h"



class SceneMain: public Scene {
    float worldScale;
    nlohmann::json configJson_;
    glm::vec2 worldSize_;
    glm::vec2 cameraPosition_;

public:
    SceneMain() = default;
    virtual ~SceneMain() = default;

    virtual void Initialize() override;
    virtual void HandleEvents(SDL_Event& event) override;
    virtual void Update(float dt) override;
    virtual void Render() override;
    virtual void Clean() override;

    void renderBackground();

    void updateCamera(float dt, const glm::vec2& target_position);

    // void addFilePathToMap();

};



#endif // SCENEMAIN_H
