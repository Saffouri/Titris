#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "Game.h"
#include "IState.h"

class MainMenuState : public IState
{
    public:
        MainMenuState(GameDataRef sharedData);
        ~MainMenuState();

        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw() override;

        void Pause() override;
        void Resume() override;

    private:
        std::vector<sf::Text> m_texts;
        sf::Sprite* m_pBgImage = nullptr;
        GameDataRef m_sharedData;
        size_t m_selected;
        bool m_inhibitKey = false;
        bool m_isChangingState = false;
};