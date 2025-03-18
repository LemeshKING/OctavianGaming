#include "Button.h"

sf::Vector2f Button::getPossition()
{
   return buttonSprite.getPosition();
}

sf::RectangleShape Button::getSprite()
{
    return buttonSprite;
}

sf::Vector2f Button::getSize()
{
   return buttonSprite.getSize();
}
