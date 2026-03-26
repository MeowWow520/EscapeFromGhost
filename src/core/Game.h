#pragma once

#ifndef GAME_H
#define GAME_H
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <glm/glm.hpp>



class Game
{
    // 变量
    glm::vec2 windowSize_ = glm::vec2(0);
    bool isRunning_ = true;
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    float delatTime_ = 0.00f;
    // 帧延迟
    Uint64 frameDelay_ = 0;
    Uint64 FPS_ = 120;
private:
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
    /**
     * 运行主循环
     * @return 返回 0：成功；返回 -1：初始化库失败。
     */
    int Running();
    int Initialize(std::string title, int width, int height); // 初始化游戏
    int handleEvents(); // 处理事件
    int Update(float dt); // 更新游戏状态
    int Render(); // 渲染游戏
    int Clean(); // 清理游戏资源
};


#endif // GAME_H    