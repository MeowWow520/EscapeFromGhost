#include "Game.h"



void Game::Running(int argc, char** argv) {
    (void)argc, (void)argv;
    while (isRunning_) {
        handleEvents();
        Update(0.0f);
        Render();
    }
}

void Game::Initialize(std::string title, int width, int height) {

    // 初始化 SDL
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) == false) isRunning_ = false;

    // 初始化 SDL_ttf
    if (TTF_Init() == false) isRunning_ = false;

    /**
     * 初始化 SDL_mixer
     * 待补全
     */

    // 创建窗口和渲染器
    SDL_CreateWindowAndRenderer(title.c_str(), width, height, SDL_WINDOW_RESIZABLE, &window_, &renderer_);
    // if (!window_ || !renderer_)

    // 设置渲染器的逻辑分辨率
    // if (SDL_SetRenderLogicalPresentation(renderer_, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX) == false)

}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning_ = false; break;
        default:
            break;
        }
    }
}

void Game::Update(float dt) { 
    (void)dt;
}

void Game::Render() { }

void Game::Clean() { 

    // 清理 SDL 库

}
