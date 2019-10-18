#pragma once
#include "StateStack.h"
#include "AssetManager.h"
#include "FrameTimer.h"
#include <memory>

struct GameData
{
    sf::RenderWindow wnd;
    StateStack statesManager;
    AssetManager assetsManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
    public:
        Game(int width, int height, std::string title);
        void Run();
    private:
        GameDataRef m_sharedData = std::make_shared<GameData>();
        float m_dt;
        FrameTimer m_ft;
};