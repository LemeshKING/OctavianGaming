#pragma once
#include<SFML/Graphics.hpp>

class Symbol
{
 private:
   sf::RectangleShape symbolSprite;
 public:
   Symbol();
   Symbol(int i, int j);
   void moveSymbol();
   void stopSymbol();
   sf::RectangleShape getSprite();
};