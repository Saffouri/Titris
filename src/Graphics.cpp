#include "Graphics.h"

void Graphics::Draw(sf::Drawable& drawable)
{
    m_wnd.draw(drawable);
}

void Graphics::PutPixel(int x, int y, sf::Color c)
{
    sf::RectangleShape pixel({1.0f, 1.0f});
    pixel.setFillColor(c);
    pixel.setPosition(sf::Vector2f(x,y));
    m_wnd.draw(pixel);
}

void Graphics::DrawRect(int x0, int y0, int x1, int y1, sf::Color c)
{
    if (x0 > x1)
        std::swap(x0, x1);
    if (y0 > y1)
        std::swap(y0, y1);

    sf::RectangleShape rect(sf::Vector2f(x1-x0, y1-y0));
    rect.setFillColor(c);
    rect.setPosition(sf::Vector2f(x0,y0));
    m_wnd.draw(rect);
}

void Graphics::CreateWindow(sf::VideoMode vmode, const std::string& title)
{
    m_wnd.create(vmode, title);
}

void Graphics::BeginFrame()
{
    m_wnd.clear();
}

void Graphics::EndFrame()
{
    m_wnd.display();
}

bool Graphics::IsWindowOpen() const
{
    return m_wnd.isOpen();
}

sf::RenderWindow& Graphics::GetWindow()
{
    return m_wnd;
}