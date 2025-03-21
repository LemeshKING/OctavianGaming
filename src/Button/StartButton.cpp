#include "StartButton.h"

StarButton::StarButton()
{
   font.loadFromFile("resources/ttt.otf");
   text.setFont(font);
   text.setOutlineThickness(0.5);
   text.setFillColor(sf::Color::Black);
   text.setString("Start");

   buttonSprite.setPosition(sf::VideoMode::getDesktopMode().width * 3 / 4, sf::VideoMode::getDesktopMode().height / 5);
   buttonSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6));
   buttonSprite.setFillColor(sf::Color::Green);
   buttonSprite.setOutlineThickness(3);
   buttonSprite.setOutlineColor(sf::Color::Black);

   text.setCharacterSize(buttonSprite.getSize().x / 3);
   text.setPosition(buttonSprite.getPosition().x + buttonSprite.getSize().x / 8, buttonSprite.getPosition().y);
}

void StarButton::onButtonClick()
{
   //логика обработки нажатия кнопки
}
