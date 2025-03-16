#include "Symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(int i, int j)
{
   symbolSprite.setPosition(sf::VideoMode::getDesktopMode().width / 160 + sf::VideoMode::getDesktopMode().width * (i + 1) / 4 - i * sf::VideoMode::getDesktopMode().width / 8, 
   sf::VideoMode::getDesktopMode().height / 108 + sf::VideoMode::getDesktopMode().height * (j + 1) / 5 + j * sf::VideoMode::getDesktopMode().height / 45);
   symbolSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5 ));
   symbolSprite.setFillColor(sf::Color::Black);
}

void Symbol::moveSymbol()
{
   //логика движения символа
}

void Symbol::stopSymbol()
{
   //логика остановки символа
}

sf::RectangleShape Symbol::getSprite()
{
    return symbolSprite;
}
