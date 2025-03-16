#include "StopButton.h"

StopButton::StopButton()
{
   buttonSprite.setPosition(sf::VideoMode::getDesktopMode().width * 3 / 4, sf::VideoMode::getDesktopMode().height * 2.75 / 4);
   buttonSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6));
   buttonSprite.setFillColor(sf::Color::Red);
}

void StopButton::onButtonClick()
{
   //логика обработки нажатия кнопки
}
