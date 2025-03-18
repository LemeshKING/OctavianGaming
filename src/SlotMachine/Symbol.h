#pragma once
#include <vector>
#include<SFML/Graphics.hpp>

class Symbol
{
 private:
   std::vector<float> startPos;
   sf::RectangleShape symbolSprite;
   sf::RectangleShape tmpSprite;
   float dy = 1;
   int numberSymbol = -1;
   bool moveTo(const float& pos,const float &lowerLimit);
 public:
   Symbol();
   Symbol(int i, int j);
   void moveSymbol(const float& lowerLimit);
   bool stopSymbol(const float& lowerLimit);
   sf::RectangleShape getSprite();
   sf::RectangleShape getTmpSprite();
};