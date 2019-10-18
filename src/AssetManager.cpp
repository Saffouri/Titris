#include "AssetManager.h"
#include <iostream>

void AssetManager::LoadFontFromFile(const std::string& name, const std::string& fileName)
{
    sf::Font font;
    if (font.loadFromFile(fileName))
    {
        m_fonts[name] = font;
    }
    else
    {
        std::cout << "Couldn't load the font!\n";
    }
    
}

const sf::Font& AssetManager::GetFont(const std::string& name) const
{
    return m_fonts.at(name);
}

void AssetManager::LoadTextureFromFile(const std::string& name, const std::string& fileName)
{
    sf::Texture texture;
    if (texture.loadFromFile(fileName))
    {
        m_textures[name] = texture;
    }
    else
    {
        std::cout << "Couldn't load the texture!\n";
    }
}

const sf::Texture& AssetManager::GetTexture(const std::string& name) const
{
    return m_textures.at(name);
}