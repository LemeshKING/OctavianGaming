#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"
#include "../SlotMachine/SlotMachine.h"

class Render
{
 private:
   sf::RenderWindow window;
   sf::Font _font;
   sf::Text _count;
 public:
   Render();
   void drawButton(std::unique_ptr<Button> &button);
   void drawReels(SlotMachine &slotMachine);
   void drawResult(int &count);
   sf::RenderWindow& getWindow();

};