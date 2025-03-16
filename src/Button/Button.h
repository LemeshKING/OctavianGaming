#pragma once
#include<string>
#include<SFML/Graphics.hpp>

class Button
{
 protected:
   sf::Font font;
   sf::Text text;
   sf::RectangleShape buttonSprite;
 public:
   virtual void onButtonClick() = 0;
   sf::Vector2f getPossition();
   sf::RectangleShape getSprite();
};