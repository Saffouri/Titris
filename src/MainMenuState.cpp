#include "MainMenuState.h"

MainMenuState::MainMenuState(GameDataRef sharedData)
    :
    m_sharedData(sharedData)
{
    m_sharedData->assetsManager.LoadFontFromFile("MENU_FONT", "ARCADECLASSIC.TTF");
    m_sharedData->assetsManager.LoadTextureFromFile("MENU_BACKGROUND_IMAGE", "MainMenuBackground.jpg");
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init()
{
    const sf::Font& font = m_sharedData->assetsManager.GetFont("MENU_FONT");

    unsigned int fontSize = 30;
    m_texts.emplace_back("Play Now", font, fontSize);
    m_texts.emplace_back("Settings and Options", font, fontSize);
    m_texts.emplace_back("Demo", font, fontSize);
    m_texts.emplace_back("Ranks", font, fontSize);

    const sf::Vector2 topLeft = {100.0f, 100.0f};

    for (size_t i = 0; i < m_texts.size(); i++)
    {
        m_texts[i].setPosition(topLeft.x, topLeft.y + i*topLeft.x);
    }
    m_selected = 0;
}

void MainMenuState::HandleInput()
{
    sf::Event event;
    while (m_sharedData->gfx.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && !m_inhibitKey)
        {
            if (event.key.code == sf::Keyboard::Down)
            {
                m_selected = (m_selected + 1) % m_texts.size();
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                m_selected = (m_selected - 1) % m_texts.size();
            } 
            if ((event.key.code == sf::Keyboard::Escape) || (event.key.code == sf::Keyboard::Return && m_selected == 0))
            {
                m_isChangingState = true;
            }
            m_inhibitKey = true;
        }
        if (event.type == sf::Event::KeyReleased)
        {
            m_inhibitKey = false;
            if (m_isChangingState)
            {
                m_sharedData->statesManager.RemoveState();
            }
        }
    }
}

void MainMenuState::Update(float dt) 
{
    dt++;
    for (size_t i=0; i < m_texts.size(); i++)
    {
        if (m_selected == i)
        {
            m_texts[i].setFillColor(sf::Color::Red);
            m_texts[i].setCharacterSize(40);
        }
        else
        {
            m_texts[i].setFillColor(sf::Color::White);
            m_texts[i].setCharacterSize(30);
        }
    }
}

void MainMenuState::Draw()
{
    for (auto& t : m_texts)
    {
        m_sharedData->gfx.Draw(t);
    }
}

void MainMenuState::Pause()
{
    std::cout << "Main Menu State Paused!\n";
}

void MainMenuState::Resume()
{
    std::cout << "Main Menu State Resumed!\n";
}