#include "SceneMain.h"



void SceneMain::Initialize()
{
    // FIXME: 关闭文件
    // 读取配置文件
    std::ifstream configJsonFile_("assets/json/config.json");
    configJsonFile_ >> configJson_;
    worldScale = configJson_["SceneMain"]["worldScale"];

    worldSize_ = gameInstance_.getWindowSize() * worldScale;
    cameraPosition_ = glm::vec2(configJson_["SceneMain"]["initCameraPos"][0], 
                                configJson_["SceneMain"]["initCameraPos"][1] );

    player_ = nullptr;
    player_ = new Player();
    player_->Initialize();
    player_->setPosition(worldSize_ / 2.0f);

}

void SceneMain::HandleEvents(SDL_Event& event)
{
    (void)event;
}

void SceneMain::Update(float dt)
{
    cameraPosition_ += glm::vec2(100.0f, 50.0f) * dt; // 每秒向右下方移动10个单位
}

void SceneMain::renderBackground()
{
    auto start = - cameraPosition_;
    auto end = worldSize_ - cameraPosition_;
    gameInstance_.drawGrid(start, end, 80.0f, {0.5, 0.5, 0.5, 1.0});
    gameInstance_.drawBoundary(start, end, 5.0f, {1.0, 1.0, 1.0, 1.0});
}

void SceneMain::updateCamera(float dt, const glm::vec2 &targetposition)
{
    (void)dt, (void)targetposition;
    cameraPosition_.x = std::max(0.0f, std::min(cameraPosition_.x, worldSize_.x - gameInstance_.getWindowSize().x));
    cameraPosition_.y = std::max(0.0f, std::min(cameraPosition_.y, worldSize_.y - gameInstance_.getWindowSize().y));

}

void SceneMain::Render()
{
    renderBackground(); // 首先渲染背景
}

void SceneMain::Clean()
{

}




/* 
void SceneMain::addFilePathToMap()
{
    // 找到背景
    const auto& backgrds = filePathJson_["SceneMain"]["backgrds"];
    for (const auto& [color, path] : backgrds.items()) {
        if (!color.compare(filePathJson_["SceneMain"]["backgrdtype"]))
            filePathMap.insert({"backgrd", path});
    }
}
*/


