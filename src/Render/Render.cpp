#include "Render.h"

Render::Render() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"SlotMachine")
{
   
}

void Render::drawButton()
{
   //отрисовка кнопок
}

void Render::drawReels()
{
   //отрисовка слот-машины
}

sf::RenderWindow& Render::getWindow()
{
   return window;
}
