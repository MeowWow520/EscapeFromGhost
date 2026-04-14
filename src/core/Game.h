#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <SDL3/SDL_mixer.h>
#include <glm/glm.hpp>
#include <nlohmann/json.hpp>
#define FCP_IMPLEMENTATION
#include "ffc.h"




class Scene;


class Game {
    // 变量
    std::string title_;
    glm::vec2 windowSize_;
    bool isRunning_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    float deltaTime_;
    nlohmann::json json_;
    // 帧延迟
    Uint64 frameDelay_;
    Uint64 FPS_;
    Scene* currentScene_;

private:
    // 私有构造函数
    Game() { 
        std::ifstream jsonFile_("assets/json/config.json");
        jsonFile_ >> json_;
        title_ = json_["window"]["title"];
        windowSize_ = glm::vec2(json_["window"]["width"], json_["window"]["height"]);
        FPS_ = json_["window"]["FPS"];

        isRunning_ = true;
        window_ = nullptr;
        renderer_ = nullptr;
        deltaTime_ = 0.00f;
        frameDelay_;
        currentScene_ = nullptr;
    }
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
    void Initialize(); // 初始化游戏
    void HandleEvents(); // 处理事件
    void Update(float dt); // 更新游戏状态
    void Render(); // 渲染游戏
    void Clean(); // 清理游戏资源

    glm::vec2 getWindowSize() const { return windowSize_; }
};


#endif // GAME_H    