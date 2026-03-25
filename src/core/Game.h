#pragma once

#ifndef GAME_H
#define GAME_H
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_mixer.h>
#include <SDL3/SDL_ttf.h>
#include <glm/glm.hpp>



class Game
{
    glm::vec2 windowSize_ = glm::vec2(0);
    bool isRunning_ = true;
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;

    // 私有构造函数
    Game() { }
    // 禁止拷贝构造函数与赋值操作符
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

public:
    static Game& getInstance() {
        static Game instance;
        return instance;
    }

    void Running(int argc, char** argv); // 运行游戏, 执行游戏主循环
    void Initialize(std::string title, int width, int height); // 初始化游戏
    void handleEvents(); // 处理事件
    void Update(float dt); // 更新游戏状态
    void Render(); // 渲染游戏
    void Clean(); // 清理游戏资源
};


#endif // GAME_H    