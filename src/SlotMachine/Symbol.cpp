#include "Symbol.h"

std::vector<int> numPosToStop;
int k = 0;

bool Symbol::moveTo(const float& pos, const float& lowerLimit)
{
   if (sprite.getPosition().y != pos)
   {
      if(abs(sprite.getPosition().y - pos) < dy)
      {
         sprite.setPosition(sprite.getPosition().x, pos);
         return true;
      }
      sprite.move(0, dy);
   }
   
   


   if (sprite.getPosition().y + sprite.getGlobalBounds().height > lowerLimit)
   {
      sprite.setTextureRect(sf::IntRect(0, 0, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height - dy));
      nextSprite.setPosition(sprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      nextSprite.setTextureRect(sf::IntRect(0, sprite.getGlobalBounds().height, 213, sf::VideoMode::getDesktopMode().height / 5 - sprite.getGlobalBounds().height));
   }
   if(sprite.getPosition().y >= lowerLimit)
   {
      sprite = nextSprite;
      sprite.setTextureRect(sf::IntRect(0, 0, sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5));
      std::random_device rd; 
      std::mt19937 gen(rd()); 
      std::uniform_int_distribution<int> dist(0, 4);
      numberTexture = numberNextTexture;
      numberNextTexture = dist(gen);
      nextSprite.setTextureRect(sf::IntRect(0, 0, _texture[numberNextTexture]->getSize().x, 0));
      nextSprite.setTexture(*_texture[numberNextTexture]);
      nextSprite.setPosition(sprite.getPosition());
   }

   return sprite.getPosition().y == pos;
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


}

void Symbol::moveSymbol(const float& lowerLimit)
{
   if(k > 3)
   {
      numPosToStop.resize(3, -1);
      k = 0;
   }
   dy +=0.005;
   if(dy > 5)
      dy = 5;
   if(dy < 0.5)
      dy = 0.5;
   if(sprite.getPosition().y + sprite.getGlobalBounds().height < lowerLimit)
      sprite.move(0, dy);
   else if(sprite.getPosition().y < lowerLimit)
   {

      sprite.setTextureRect(sf::IntRect(0,0,sprite.getGlobalBounds().width, sprite.getGlobalBounds().height - dy));
      sprite.move(0, dy);
      nextSprite.setPosition(sprite.getPosition().x, sf::VideoMode::getDesktopMode().height / 5);
      nextSprite.setTextureRect(sf::IntRect(0, sprite.getGlobalBounds().height, 213, sf::VideoMode::getDesktopMode().height / 5 - sprite.getGlobalBounds().height));
   }
   else 
   {
      sprite = nextSprite;
      sprite.setTextureRect(sf::IntRect(0,0, sf::VideoMode::getDesktopMode().width / 9, sf::VideoMode::getDesktopMode().height / 5));
      std::random_device rd; 
      std::mt19937 gen(rd()); 
      std::uniform_int_distribution<int> dist(0, 4);
      numberTexture = numberNextTexture;
      numberNextTexture = dist(gen);
      nextSprite.setTextureRect(sf::IntRect(0, 0, _texture[numberNextTexture]->getSize().x, 0));
      nextSprite.setTexture(*_texture[numberNextTexture]);
      nextSprite.setPosition(sprite.getPosition());
   }
      
}


bool Symbol::stopSymbol(const float& lowerLimit)
{
   bool tmp = false;
   if(dy > 0.5)
   {
      dy -= 0.01;
      moveSymbol(lowerLimit);
      
   }
   else 
   {
      k++;
      dy = 0.5;
      float ySymbolPosition = sprite.getPosition().y;
      if(numPosToStop[numberSymbol] == -1)
      {
         if (startPos[1] - ySymbolPosition > 0 )
            numPosToStop[numberSymbol] = 1;
         else if (startPos[2] - ySymbolPosition > 0 )
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

      tmp = moveTo(startPos[numPosToStop[numberSymbol]], lowerLimit);
   }

   return tmp;
   
}

void Symbol::standOnBestPos()
{
   if(nextSprite.getGlobalBounds().height > 0)
   {
      sprite = nextSprite;
      numberTexture = numberNextTexture;
   }

   sprite.setPosition(sprite.getPosition().x,startPos[numPosToStop[numberSymbol]]);
   sprite.setTextureRect(sf::IntRect(0,0, sf::VideoMode::getDesktopMode().width / 9,sf::VideoMode::getDesktopMode().height / 5));
   nextSprite.setTextureRect(sf::IntRect(0,0, nextSprite.getGlobalBounds().width, 0));
}

sf::Sprite Symbol::getSprite()
{
    return sprite;
}

sf::Sprite Symbol::getNextSprite()
{
   return nextSprite;
}

void Symbol::setTexture(std::vector<std::shared_ptr<sf::Texture>>& texture)
{
   std::random_device rd;  
   std::mt19937 gen(rd()); 
   std::uniform_int_distribution<int> dist(0, 4); 
   numberTexture = dist(gen);
   numberNextTexture = dist(gen);
   _texture = texture;
   sprite.setTextureRect(sf::IntRect(0, 0, _texture[numberTexture]->getSize().x, _texture[numberTexture]->getSize().y));
   sprite.setTexture(*_texture[numberTexture]);
   sprite.setPosition(symbolSprite.getPosition());
   nextSprite.setTextureRect(sf::IntRect(0, 0, _texture[numberNextTexture]->getSize().x, 0));
   nextSprite.setTexture(*_texture[numberNextTexture]);
   nextSprite.setPosition(symbolSprite.getPosition());
}

int Symbol::getNumberTexture()
{
   return numberTexture;
}

std::vector<int> Symbol::getPosToStop()
{
   return numPosToStop;
}
