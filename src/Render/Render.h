#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"
#include "../SlotMachine/SlotMachine.h"

class Render
{
 private:
   sf::RenderWindow window;
 public:
   Render();
   void drawButton(std::unique_ptr<Button> &button);
   void drawReels(/*SlotMachine &slotMachine*/);
   sf::RenderWindow& getWindow();

};