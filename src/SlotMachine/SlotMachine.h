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
   SlotMachine();
   void spinReels();
   void stopReels();
   void getResult();
   ReelVector getReels();
   sf::RectangleShape getSprite();
};