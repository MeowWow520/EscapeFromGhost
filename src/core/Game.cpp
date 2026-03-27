#include "Game.h"
#include "../SceneMain.h"



int Game::Running(int argc, char *argv[]) {
    (void)argc, (void)argv;

    while (isRunning_) {
        // 计算帧率延迟
        Uint64 start = SDL_GetTicksNS();



        //<!-- START 逻辑处理
        handleEvents();
        Update(delatTime_);
        Render();
        //<!-- END 逻辑处理



        // 计算帧率延迟
        Uint64 end = SDL_GetTicksNS();
        Uint64 elapsed = end - start;
        if (elapsed < frameDelay_) {
            Uint64 sdlDelatTimesNS = frameDelay_ - elapsed;
            SDL_DelayNS(sdlDelatTimesNS);
            delatTime_ = (float)(frameDelay_ / 1.0e9);
        } else { delatTime_ = (float)(elapsed / 1.0e9); }
    }
    return 0;
}

int Game::Initialize(std::string title, int width, int height) {

    // 初始化 SDL
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) == false) {
        SDL_Log("Couldn't initialize SDL_Init: %s", SDL_GetError());
        isRunning_ = false;
        return -1;
    }
    // 初始化 SDL_ttf
    if (TTF_Init() == false) {
        SDL_Log("Couldn't initialize TTF_Init: %s", SDL_GetError());
        isRunning_ = false;
        return -1;
    }
    // 初始化 SDL_mixer
    if (!MIX_Init()) {
       SDL_Log("Couldn't initialize MIX_Init: %s", SDL_GetError());
       isRunning_ = false;
       return -1;
    }
    // 初始化 mixer 设置   ------ 待补全
    // 创建窗口
    window_ = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
    if (!window_) {
        SDL_Log("SDL create window failed: %s", SDL_GetError());
        isRunning_ = false;
        return -1;
    }

    // 创建渲染器
    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (!renderer_) {
        SDL_Log("SDL create renderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window_);
        window_ = nullptr;
        isRunning_ = false;
        return -1;
    }
    // 设置渲染器的逻辑分辨率
    if (SDL_SetRenderLogicalPresentation(renderer_, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX) == false) {
        SDL_Log("SDL Renderer setting logical presentation failed: %s", SDL_GetError());
        isRunning_ = false;
        return -1;
    }

    // 计算帧延迟
    frameDelay_ = (Uint64)1e9 / FPS_;
    return 0;
}

int Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning_ = false;
            SDL_Log("Received SDL_EVENT_QUIT event, main loop quit");
            break;
        default:
            break;
        }
    }
    return 0;
}

int Game::Update(float dt) {
    (void)dt;
    return 0;
}

int Game::Render() { 
    return 0;
}

int Game::Clean() { 

    // 清理 SDL 库
    SDL_Quit();
    MIX_Quit();
    TTF_Quit();

    // 清理 SDL 资源
    return 0;
}