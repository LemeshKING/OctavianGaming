#pragma once
#include "Symbol.h"
#include <vector>

typedef std::vector<Symbol> SymbolVector;

class Reel
{
 private:
   SymbolVector symbols;
   sf::RectangleShape reelSprite;
 public:
   Reel();
   Reel(int i);
   void spinReel();
   bool stopReel();
   sf::RectangleShape getSprite();
   SymbolVector getSymbols();
};