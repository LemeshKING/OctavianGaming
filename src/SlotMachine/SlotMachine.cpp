#include "SlotMachine.h"

SlotMachine::SlotMachine(TextureManager& textureManager)
{
   slotMachineSprite.setPosition(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6);
   slotMachineSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.1, sf::VideoMode::getDesktopMode().height / 1.36));
   slotMachineSprite.setFillColor(sf::Color::Magenta);
   slotMachineSprite.setOutlineThickness(2);
   slotMachineSprite.setOutlineColor(sf::Color::Black);
   reels.resize(3);
   for(int i = 0; i < reels.size(); i++)
      reels[i] = Reel(textureManager, i);
}

void SlotMachine::spinReels()
{
   //логика врещения слотов
   for(auto &reel : reels)
      reel.spinReel();
}

bool SlotMachine::stopReels()
{
   //логика остановки слотов
   bool tmp = false;
   for (auto& reel : reels)
     tmp = reel.stopReel();
   return tmp;
}

int SlotMachine::getResult()
{
   if(reels[0].getResult() == reels[1].getResult() && reels[0].getResult() == reels[2].getResult())
      return 2;
   else if(reels[0].getResult() == reels[1].getResult() || reels[0].getResult() == reels[2].getResult() || reels[1].getResult() == reels[2].getResult())
      return 1;
   else 
      return 0;
      
}

ReelVector SlotMachine::getReels()
{
    return reels;
}

sf::RectangleShape SlotMachine::getSprite()
{
   return slotMachineSprite;
}
