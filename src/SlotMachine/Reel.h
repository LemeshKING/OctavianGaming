#pragma once
#include "Symbol.h"
#include "../TextureManager/TextureManager.h"
#include <vector>

typedef std::vector<Symbol> SymbolVector;

class Reel
{
 private:
   SymbolVector symbols;
   
   sf::RectangleShape reelSprite;
   std::vector<std::shared_ptr<sf::Texture>> symbolsTexture;
   std::vector<std::string> symbolFiles;
 public:
   Reel();
   Reel(TextureManager& textureManager, int i);
   void spinReel();
   bool stopReel();
   sf::RectangleShape getSprite();
   SymbolVector getSymbols();
   int getResult();
};