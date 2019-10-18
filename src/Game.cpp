#include "Game.h"
#include "MainMenuState.h"
Game::Game(int width, int height, std::string title)
{
    m_sharedData->wnd.create(sf::VideoMode(width, height), title);
    m_sharedData->statesManager.AddState(std::make_unique<MainMenuState>(m_sharedData));
    Run();
}

void Game::Run()
{
    while(m_sharedData->wnd.isOpen())
    {
        m_dt = m_ft.Mark();
        m_sharedData->wnd.clear();      //begin frame
        m_sharedData->statesManager.ProcessStateChanges();
        if (m_sharedData->statesManager.IsEmpty())
            break;
        m_sharedData->statesManager.GetActiveState()->HandleInput();
        m_sharedData->statesManager.GetActiveState()->Update(m_dt);
        m_sharedData->statesManager.GetActiveState()->Draw();
        m_sharedData->wnd.display();    //end frame
    }
    std::cout << "Program Terminated successfully\n";
}