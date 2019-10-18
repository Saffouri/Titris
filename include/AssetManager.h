#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class AssetManager
{
    public:
        void LoadFontFromFile(const std::string& name, const std::string& fileName);
        const sf::Font& GetFont(const std::string& name) const;
        void LoadTextureFromFile(const std::string& name, const std::string& fileName);
        const sf::Texture& GetTexture(const std::string& name) const;
    private:
        std::map<std::string, sf::Font> m_fonts;
        std::map<std::string, sf::Texture> m_textures;
};