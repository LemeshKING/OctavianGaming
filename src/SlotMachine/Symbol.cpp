#include "Symbol.h"

std::vector<int> numPosToStop;
bool fuckoff = false;
int k = 0;

bool Symbol::moveTo(const float& pos, const float& lowerLimit)
{
   if(fuckoff)
   {
      symbolSprite.setPosition(symbolSprite.getPosition().x, pos);
      symbolSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, sf::VideoMode::getDesktopMode().height / 5));
      tmpSprite.setSize(sf::Vector2f(tmpSprite.getSize().x,0));
   }
   if (symbolSprite.getPosition().y != pos)
   {
      symbolSprite.move(0, dy);
      fuckoff = true;
   }

   if (symbolSprite.getPosition().y + symbolSprite.getSize().y > lowerLimit)
   {
      symbolSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, symbolSprite.getSize().y - dy));
      tmpSprite.setPosition(symbolSprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      tmpSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, tmpSprite.getSize().y + dy));
   }
   if(symbolSprite.getPosition().y >= lowerLimit)
   {
      symbolSprite.setPosition(symbolSprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      symbolSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5));
      tmpSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, 0));
   }

   return symbolSprite.getPosition().y == pos;
}

Symbol::Symbol()
{
}

Symbol::Symbol(int i, int j)
{
   numPosToStop.resize(3,-1);
   numberSymbol = j;
   symbolSprite.setPosition(sf::VideoMode::getDesktopMode().width / 160 + sf::VideoMode::getDesktopMode().width * (i + 1) / 4 - i * sf::VideoMode::getDesktopMode().width / 8, 
   sf::VideoMode::getDesktopMode().height / 90 + sf::VideoMode::getDesktopMode().height * (j + 1)  / 5 + j * sf::VideoMode::getDesktopMode().height / 45 );
   startPos.resize(3);
   startPos[0] = sf::VideoMode::getDesktopMode().height / 90 + sf::VideoMode::getDesktopMode().height  / 5;
   startPos[1] = sf::VideoMode::getDesktopMode().height / 90 + sf::VideoMode::getDesktopMode().height * 2 / 5 + sf::VideoMode::getDesktopMode().height / 45;
   startPos[2] = sf::VideoMode::getDesktopMode().height / 90 + sf::VideoMode::getDesktopMode().height * 3 / 5 + 2 * sf::VideoMode::getDesktopMode().height / 45;
   symbolSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5 ));
   symbolSprite.setFillColor(sf::Color(0,0,0,255));
   tmpSprite = symbolSprite;
   tmpSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 9, 0));
}

void Symbol::moveSymbol(const float& lowerLimit)
{
   dy +=0.0005;
   if(dy > 5)
      dy = 5;
   if(dy < 0.5)
      dy = 0.5;
   if(symbolSprite.getPosition().y + symbolSprite.getSize().y < lowerLimit)
      symbolSprite.move(0, dy);
   else if(symbolSprite.getPosition().y < lowerLimit)
   {
      symbolSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, symbolSprite.getSize().y - dy));
      symbolSprite.move(0, dy);
      tmpSprite.setPosition(symbolSprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      tmpSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, tmpSprite.getSize().y + dy));
   }
   else 
   {
      symbolSprite.setPosition(symbolSprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      symbolSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5));
      tmpSprite.setSize(sf::Vector2f(symbolSprite.getSize().x, 0));
   }
      
}


bool Symbol::stopSymbol(const float& lowerLimit)
{
   bool tmp = false;
   if(dy > 0.5)
   {
      dy -= 0.001;
      moveSymbol(lowerLimit);
      
   }
   else 
   {
      k++;
      dy = 0.5;
      float ySymbolPosition = symbolSprite.getPosition().y;
      if(numPosToStop[numberSymbol] == -1)
      {
         if (startPos[1] - ySymbolPosition > 0 && abs(startPos[1] - ySymbolPosition) < abs(startPos[0] - ySymbolPosition))
            numPosToStop[numberSymbol] = 1;
         else if (startPos[2] - ySymbolPosition > 0 && abs(startPos[2] - ySymbolPosition) < abs(startPos[0] - ySymbolPosition))
            numPosToStop[numberSymbol] = 2;
         else
            numPosToStop[numberSymbol] = 0;
      }
      if(k == 3)
      {
         for (int i = 1; i < numPosToStop.size(); i++)
            if (numPosToStop[i - 1] == numPosToStop[i])
               numPosToStop[i]++;
         for (int i = 0; i < numPosToStop.size(); i++)
            if (numPosToStop[i] == 3)
               numPosToStop[i] = 0;
      }

      tmp = moveTo(startPos[numberSymbol], lowerLimit);
   }

   return tmp;
   
}

sf::RectangleShape Symbol::getSprite()
{
    return symbolSprite;
}

sf::RectangleShape Symbol::getTmpSprite()
{
   return tmpSprite;
}
