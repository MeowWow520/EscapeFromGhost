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

        // 计算帧率
        {
            Uint64 end = SDL_GetTicksNS();
            Uint64 elapsed = end - start;
            if (elapsed < frameDelay_) {
                Uint64 sdlDelatTimesNS = frameDelay_ - elapsed;
                SDL_DelayNS(sdlDelatTimesNS);
                deltaTime_ = (float)(frameDelay_ / 1e9);
            } else { deltaTime_ = (float)(elapsed / 1e9); }
        }
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
    renderer_ = ffc::cfp(SDL_CreateRenderer(window_, NULL));
    // 设置渲染器的逻辑分辨率
    ffc::cfb(SDL_SetRenderLogicalPresentation(renderer_, 
                                              static_cast<int>(windowSize_.x), 
                                              static_cast<int>(windowSize_.y), 
                                              SDL_LOGICAL_PRESENTATION_LETTERBOX));

    // 创建场景类
    if (currentScene_ == nullptr)
        currentScene_ = new SceneMain();
    currentScene_->Initialize();
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            isRunning_ = false;
            break;
        default:
            currentScene_->HandleEvents(event);
            break;
        }
    }
}

void Game::Update(float dt)
{
    currentScene_->Update(dt);
}

void Game::Render()
{ 
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    currentScene_->Render();
    SDL_RenderPresent(renderer_);
}

void Game::Clean() { 

    // 销毁当前场景
    if (currentScene_ != nullptr) {
         currentScene_->Clean();
         delete currentScene_;
         currentScene_ = nullptr; }
    
    // 销毁窗口和渲染器
    if ((renderer_ != nullptr) && window_ != nullptr ) {
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(renderer_);
    } else { SDL_Log("SDL window or renderer is nullptr"); }
    
    // 清理 SDL 库
    SDL_Quit();
    MIX_Quit();
    TTF_Quit();

    // TODO: 清理 SDL 资源
}


void Game::drawGrid(const glm::vec2 &top_left, const glm::vec2 &botton_right, float grid_width, SDL_FColor fcolor)
{
    SDL_SetRenderDrawColorFloat(renderer_, fcolor.r, fcolor.g, fcolor.b, fcolor.a);
    for (float x = top_left.x; x <= botton_right.x; x += grid_width){
        SDL_RenderLine(renderer_, x, top_left.y, x, botton_right.y);
    }
    for (float y = top_left.y; y <= botton_right.y; y += grid_width){
        SDL_RenderLine(renderer_, top_left.x, y, botton_right.x, y);
    }
    SDL_SetRenderDrawColorFloat(renderer_, 0, 0, 0, 1);
}


void Game::drawBoundary(const glm::vec2 &top_left, const glm::vec2 &botton_right, float boundary_width, SDL_FColor fcolor)
{
    SDL_SetRenderDrawColorFloat(renderer_, fcolor.r, fcolor.g, fcolor.b, fcolor.a);
    for (float i = 0; i < boundary_width; i++){
        SDL_FRect rect = {
            top_left.x - i,
            top_left.y - i,
            botton_right.x - top_left.x + 2 * i,
            botton_right.y - top_left.y + 2 * i
        };
        SDL_RenderRect(renderer_, &rect);
    }
    SDL_SetRenderDrawColorFloat(renderer_, 0, 0, 0, 1);
}