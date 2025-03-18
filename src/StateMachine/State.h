#pragma once
#include"../SlotMachine/SlotMachine.h"
#include <iostream>

class State
{
 public:
   virtual ~State() = default;
   virtual void enter() = 0;
   virtual void update() = 0;
   virtual void exit() = 0;
};