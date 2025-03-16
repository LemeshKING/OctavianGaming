#pragma once
#include "Symbol.h"
#include <vector>

typedef std::vector<char> SymbolVector;

class Reel
{
 private:
   SymbolVector symbols;
 public:
   void spinReel();
   void stopReel();
};