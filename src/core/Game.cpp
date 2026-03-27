#include "Game.h"
#include "../SceneMain.h"



void Game::Running(int argc, char *argv[]) {
    (void)argc, (void)argv;

    while (isRunning_) {
        // 计算帧率延迟
        Uint64 start = SDL_GetTicksNS();



        //<!-- START 逻辑处理
        handleEvents();
        Update(deltaTime_);
        Render();
        //<!-- END 逻辑处理



        // 计算帧率延迟
        Uint64 end = SDL_GetTicksNS();
        Uint64 elapsed = end - start;
        if (elapsed < frameDelay_) {
            Uint64 sdlDelatTimesNS = frameDelay_ - elapsed;
            SDL_DelayNS(sdlDelatTimesNS);
            deltaTime_ = (float)(frameDelay_ / 1.0e9);
        } else { deltaTime_ = (float)(elapsed / 1.0e9); }
    }
}

void Game::Initialize(std::string title, int width, int height) {

    // 初始化 SDL
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) == false) {
        SDL_Log("Couldn't initialize SDL_Init: %s", SDL_GetError());
        isRunning_ = false;
    }
    // 初始化 SDL_ttf
    if (TTF_Init() == false) {
        SDL_Log("Couldn't initialize TTF_Init: %s", SDL_GetError());
        isRunning_ = false;
    }
    // 初始化 SDL_mixer
    if (MIX_Init() == false) {
       SDL_Log("Couldn't initialize MIX_Init: %s", SDL_GetError());
       isRunning_ = false;
    }
    // 初始化 mixer 设置   ------ 待补全
    // 创建窗口
    window_ = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
    if (!window_) {
        SDL_Log("SDL create window failed: %s", SDL_GetError());
        isRunning_ = false;
    }

    // 创建渲染器
    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (!renderer_) {
        SDL_Log("SDL create renderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window_);
        window_ = nullptr;
        isRunning_ = false;
    }
    // 设置渲染器的逻辑分辨率
    if (SDL_SetRenderLogicalPresentation(renderer_, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX) == false) {
        SDL_Log("SDL Renderer setting logical presentation failed: %s", SDL_GetError());
        isRunning_ = false;
    }

    // 计算帧延迟
    frameDelay_ = (Uint64)1e9 / FPS_;

    // 创建场景类
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning_ = false;
            SDL_Log("Received SDL_EVENT_QUIT event, main loop quit");
            break;
        default:
            // currentScene_->handleEvents(event);
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
    if (renderer_ != nullptr && window_ != nullptr ) {
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(renderer_);
    } else { SDL_Log("SDL window or renderer is nullptr"); }
    // 清理 SDL 库
    SDL_Quit();
    MIX_Quit();
    TTF_Quit();

    // 清理 SDL 资源
}