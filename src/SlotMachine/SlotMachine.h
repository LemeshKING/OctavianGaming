#pragma once
#include "Reel.h"
#include <vector>

typedef std::vector<Reel> ReelVector; 

class SlotMachine
{
 private:
   ReelVector reels;
   sf::RectangleShape slotMachineSprite;
 public:
   SlotMachine(TextureManager &textureManager);
   void spinReels();
   bool stopReels();
   int getResult();
   ReelVector getReels();
   sf::RectangleShape getSprite();
};