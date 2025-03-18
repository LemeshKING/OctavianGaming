#include "ResultState.h"

ResultState::ResultState(SlotMachine& slotMachine)
{
   _slotMachine = &slotMachine;
}

void ResultState::enter()
{
   //логика входа в состо€ние
}

void ResultState::update()
{
   if(_slotMachine->stopReels())
      _slotMachine->getResult();
}

void ResultState::exit()
{
   //логика выхода из состо€ни€
}
