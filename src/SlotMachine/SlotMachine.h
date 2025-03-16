#pragma once
#include "Reel.h"
#include <vector>

typedef std::vector<int> ReelVector; 

class SlotMachine
{
 private:
   ReelVector reels;
 public:
   void spinReels();
   void stopReels();
   void getResult();
};