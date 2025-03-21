#pragma once
#include <vector>
#include <random>
#include <iostream>
#include<SFML/Graphics.hpp>



class Symbol
{
 private:
   sf::Sprite sprite;
   sf::Sprite nextSprite;
   std::vector<std::shared_ptr<sf::Texture>> _texture;
   std::vector<float> startPos;
   sf::RectangleShape symbolSprite;
   float dy = 1;
   int numberTexture = 0;
   int numberNextTexture = 0;
   int numberSymbol = -1;
   bool moveTo(const float& pos,const float &lowerLimit);
 public:
   Symbol();
   Symbol(int i, int j);
   void moveSymbol(const float& lowerLimit);
   bool stopSymbol(const float& lowerLimit);
   void standOnBestPos();
   sf::Sprite getSprite();
   sf::Sprite getNextSprite();
   void setTexture(std::vector<std::shared_ptr<sf::Texture>>& texture);
   int getNumberTexture();
   std::vector<int> getPosToStop();

};