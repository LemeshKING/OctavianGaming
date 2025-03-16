#include "Reel.h"

Reel::Reel()
{
}

Reel::Reel(int i)
{
   reelSprite.setPosition(sf::VideoMode::getDesktopMode().width * (i + 1) / 4 - i * sf::VideoMode::getDesktopMode().width / 8, sf::VideoMode::getDesktopMode().height / 5);
   reelSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8, sf::VideoMode::getDesktopMode().height / 1.5));
   reelSprite.setFillColor(sf::Color::Yellow);
   reelSprite.setOutlineThickness(1.5);
   reelSprite.setOutlineColor(sf::Color::Black);
   symbols.resize(3);
   for(int j = 0; j < symbols.size(); j++)
      symbols[j] = Symbol(i, j);
}

void Reel::spinReel()
{
   //логика вращения слота
}

void Reel::stopReel()
{
   //логика остановки слота
}

sf::RectangleShape Reel::getSprite()
{
    return reelSprite;
}

SymbolVector Reel::getSymbols()
{
   return symbols;
}
