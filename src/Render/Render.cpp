#include "Render.h"

Render::Render() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"SlotMachine")
{
   
}

void Render::drawButton(std::unique_ptr<Button>& button)
{
   window.draw(button->getSprite());
}

void Render::drawReels()
{
   //��������� ����-������
}

sf::RenderWindow& Render::getWindow()
{
   return window;
}
