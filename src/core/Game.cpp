#include "Game.h"
#include "../SceneMain.h"



void Game::Running(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    while (isRunning_)
    {
        // 计算帧率延迟
        Uint64 start = SDL_GetTicksNS();

        //<!-- START 逻辑处理
        HandleEvents();
        Update(deltaTime_);
        Render();
        //<!-- END 逻辑处理

        // 计算帧率延迟
        Uint64 end = SDL_GetTicksNS();
        Uint64 elapsed = end - start;
        if (elapsed < frameDelay_) {
            Uint64 sdlDelatTimesNS = frameDelay_ - elapsed;
            SDL_DelayNS(sdlDelatTimesNS);
            deltaTime_ = (float)(frameDelay_ / 1e9);
        } else { deltaTime_ = (float)(elapsed / 1e9); }
    }
}

void Game::Initialize()
{
    // 初始化 SDL
    ffc::cfb(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO));
    ffc::cfb(TTF_Init());
    ffc::cfb(MIX_Init());
    // TODO:    初始化 mixer 设置

    // 创建窗口
    window_ = ffc::cfp(SDL_CreateWindow(title_.c_str(), 
                                        static_cast<int>(windowSize_.x),
                                        static_cast<int>(windowSize_.y),
                                        SDL_WINDOW_RESIZABLE));
    
    // 创建渲染器
    renderer_ = ffc::cfp(SDL_CreateRenderer(window_, nullptr));
    // 设置渲染器的逻辑分辨率
    ffc::cfb(SDL_SetRenderLogicalPresentation(renderer_, 
                                              static_cast<int>(windowSize_.x), 
                                              static_cast<int>(windowSize_.y), 
                                              SDL_LOGICAL_PRESENTATION_LETTERBOX));

    // 计算帧延迟
    frameDelay_ = (Uint64)1e9 / FPS_;

    // 创建场景类
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning_ = false;
            break;
        default:
            // currentScene_->HandleEvents(event);
            break;
        }
    }
}

void Game::Update(float dt) {
    (void)dt;
    // currentScene_->Update(dt);
}

void Game::Render() { 
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    // currentScene_->Render();
    SDL_RenderPresent(renderer_);
}

void Game::Clean() { 

    // 销毁当前场景
    // if (currentScene_ != nullptr) {
    //     currentScene_->Clean();
    //     delete currentScene_;
    //     currentScene_ = nullptr;
    // }
    // 销毁窗口和渲染器
    if ((renderer_ != nullptr) && window_ != nullptr ) {
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(renderer_);
    } else { SDL_Log("SDL window or renderer is nullptr"); }
    // 清理 SDL 库
    SDL_Quit();
    MIX_Quit();
    TTF_Quit();

    // 清理 SDL 资源
}
