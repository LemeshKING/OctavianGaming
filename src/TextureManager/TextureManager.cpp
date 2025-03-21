#include "TextureManager.h"

std::shared_ptr<sf::Texture> TextureManager::getTexture(const std::string& filename)
{
   
   if (textures.find(filename) == textures.end())
   {
      auto texture = std::make_shared<sf::Texture>();
      if (!texture->loadFromFile(filename))
         return nullptr;

      textures[filename] = texture;
   }
   return textures[filename];
   
}
