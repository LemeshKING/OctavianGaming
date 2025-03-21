#include "Reel.h"

Reel::Reel()
{
}

Reel::Reel(TextureManager& textureManager, int i)
{
   symbolFiles.resize(5);
   for(int j = 0; j < symbolFiles.size(); j++)
      symbolFiles[j] = "resources/" + std::to_string(j + 1) + ".png";
   for (const auto& file : symbolFiles) 
   {
      auto texture = textureManager.getTexture(file);
      if (texture) 
         symbolsTexture.push_back(texture);
      
   }
   reelSprite.setPosition(sf::VideoMode::getDesktopMode().width * (i + 1) / 4 - i * sf::VideoMode::getDesktopMode().width / 8, sf::VideoMode::getDesktopMode().height / 5);
   reelSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8, sf::VideoMode::getDesktopMode().height / 1.5));
   reelSprite.setFillColor(sf::Color::Yellow);
   reelSprite.setOutlineThickness(1.5);
   reelSprite.setOutlineColor(sf::Color::Black);
   symbols.resize(3);
   for(int j = 0; j < symbols.size(); j++)
   {
      symbols[j] = Symbol(i, j);
      symbols[j].setTexture(symbolsTexture);
   }

}

void Reel::spinReel()
{
   //логика вращения слота
   for(auto &symbol : symbols)
      symbol.moveSymbol(reelSprite.getPosition().y + reelSprite.getSize().y);
}

bool Reel::stopReel()
{
   //логика остановки слота
   bool tmp = false;
   for (auto& symbol : symbols)
     tmp = symbol.stopSymbol(reelSprite.getPosition().y + reelSprite.getSize().y);
   if(tmp)
      for (auto& symbol : symbols)
        symbol.standOnBestPos();
   return tmp;
}

sf::RectangleShape Reel::getSprite()
{
    return reelSprite;
}

SymbolVector Reel::getSymbols()
{
   return symbols;
}

int Reel::getResult()
{
   int number = 0;
   std::vector<int> tmp = symbols[0].getPosToStop();
   for(int i = 0; i < tmp.size(); i++)
      if(tmp[i] == 1)
         number = i;
   return symbols[number].getNumberTexture();
}
