#include "Render.h"

Render::Render() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"SlotMachine")
{
   _font.loadFromFile("resources/ttt.otf");
   _count.setFont(_font);
   _count.setCharacterSize(48);
   _count.setOutlineThickness(0.5);
   _count.setFillColor(sf::Color::Black);
   _count.setPosition(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 10);
}

void Render::drawButton(std::unique_ptr<Button>& button)
{
   window.draw(button->getSprite());
   window.draw(button->getText());
}

void Render::drawReels(SlotMachine& slotMachine)
{
   window.draw(slotMachine.getSprite());
   for(auto& reel : slotMachine.getReels())
   {
      window.draw(reel.getSprite());
      for(auto &symbol : reel.getSymbols())
      {
         window.draw(symbol.getSprite());
         window.draw(symbol.getNextSprite());
      }
   }


}

void Render::drawResult(int& count)
{
   _count.setString("Count of matches: " + std::to_string(count));
   window.draw(_count);
}

sf::RenderWindow& Render::getWindow()
{
   return window;
}
