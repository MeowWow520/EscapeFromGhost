#ifndef GAME_H
#define GAME_H
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <SDL3/SDL_mixer.h>
#include <glm/glm.hpp>
#include "../SceneMain.h"

class Object;

class Game {
private:

class Scene;


class Game
{
    // 变量
    glm::vec2 windowSize_ = glm::vec2(0);
    bool isRunning_ = true;
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    float deltaTime_ = 0.00f;
    // 帧延迟
    Uint64 frameDelay_ = 0;
    Uint64 FPS_ = 120;
    Scene* currentScene_ = nullptr;

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
     * @return 返回 0：成功；返回 -1：运行失败。
     */
    void Running(int argc, char *argv[]);
    /**
     * 初始化资源，初始化 SDL 字体库、图片库、音效库。
     * @param title 窗口标题
     * @param width 窗口宽度
     * @param height 窗口高度
     * @return 返回 0：成功；返回 -1：初始化失败。
     */   
    void Initialize(std::string title, int width, int height); // 初始化游戏
    void handleEvents(); // 处理事件
    void Update(float dt); // 更新游戏状态
    void Render(); // 渲染游戏
    void Clean(); // 清理游戏资源
};


#endif // GAME_H    