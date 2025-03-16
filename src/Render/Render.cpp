#include "Render.h"

Render::Render() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"SlotMachine")
{
   
}

void Render::drawButton(std::unique_ptr<Button>& button)
{
   window.draw(button->getSprite());
}

void Render::drawReels(SlotMachine& slotMachine)
{
   window.draw(slotMachine.getSprite());
   for(auto& reel : slotMachine.getReels())
   {
      window.draw(reel.getSprite());
      for(auto &symbol : reel.getSymbols())
         window.draw(symbol.getSprite());
   }
}

sf::RenderWindow& Render::getWindow()
{
   return window;
}
