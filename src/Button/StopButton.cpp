#include "StopButton.h"

StopButton::StopButton()
{
   font.loadFromFile("resources/ttt.otf");
   text.setFont(font);
   text.setOutlineThickness(0.5);
   text.setFillColor(sf::Color::Black);
   text.setString("Stop");

   buttonSprite.setPosition(sf::VideoMode::getDesktopMode().width * 3 / 4, sf::VideoMode::getDesktopMode().height * 2.75 / 4);
   buttonSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6));
   buttonSprite.setFillColor(sf::Color::Red);
   buttonSprite.setOutlineThickness(3);
   buttonSprite.setOutlineColor(sf::Color::Black);

   text.setCharacterSize(buttonSprite.getSize().x / 3);
   text.setPosition(buttonSprite.getPosition().x + buttonSprite.getSize().x / 7, buttonSprite.getPosition().y);
}

void StopButton::onButtonClick()
{
   //логика обработки нажатия кнопки
}
