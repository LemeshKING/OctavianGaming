#include "Render.h"

Render::Render() : window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"SlotMachine")
{
   
}

void Render::drawButton()
{
   //��������� ������
}

void Render::drawReels()
{
   //��������� ����-������
}

sf::RenderWindow& Render::getWindow()
{
   return window;
}
