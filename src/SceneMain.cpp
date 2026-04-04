#include "SceneMain.h"



void SceneMain::Initialize() { 
    worldSize_ = gameInstance_.getWindowSize() * 3.0f;
    cameraPosition_ = glm::vec2(-100.00f, -100.00f);
 }

void SceneMain::HandleEvents(SDL_Event& event) {
    (void)event;
}

void SceneMain::Update(float dt) {
    (void)dt;
 }

void SceneMain::Render() { }

void SceneMain::Clean() { }
