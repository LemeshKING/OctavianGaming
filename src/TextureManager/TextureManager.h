#pragma once
#include <SFML/Graphics.hpp>
#include<map>
#include<memory>


class TextureManager
{
 private:
    std::map<std::string, std::shared_ptr<sf::Texture>> textures;
 public:
   std::shared_ptr<sf::Texture> getTexture(const std::string& filename);
   
   
   
};