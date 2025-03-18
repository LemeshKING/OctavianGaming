#pragma once
#include "../Button/Button.h"

class InputHandler
{
 public:
   bool isButtonPresset(std::unique_ptr<Button> &button, const sf::Vector2i &mousePos );
};