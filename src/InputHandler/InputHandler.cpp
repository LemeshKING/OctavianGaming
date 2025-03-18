#include "InputHandler.h"


bool InputHandler::isButtonPresset(std::unique_ptr<Button>& button, const sf::Vector2i& mousePos)
{
   sf::Vector2f butPos = button->getPossition();
   sf::Vector2f butSize = button->getSize();
   return mousePos.x > butPos.x && mousePos.x < butPos.x + butSize.x && mousePos.y > butPos.y && mousePos.y < butPos.y + butSize.y;
}
