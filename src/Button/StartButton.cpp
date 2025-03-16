#include "StartButton.h"

StarButton::StarButton()
{
   buttonSprite.setPosition(sf::VideoMode::getDesktopMode().width * 3 / 4, sf::VideoMode::getDesktopMode().height / 5);
   buttonSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6));
   buttonSprite.setFillColor(sf::Color::Green);
}

void StarButton::onButtonClick()
{
   //логика обработки нажатия кнопки
}
