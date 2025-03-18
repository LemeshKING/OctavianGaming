#include "SpinningState.h"

SpinningState::SpinningState(SlotMachine& slotMachine)
{
   _slotMachine = &slotMachine;
}

void SpinningState::enter()
{
   std::cout << "Start spinning" << std::endl;
}

void SpinningState::update()
{
   _slotMachine->spinReels();
}

void SpinningState::exit()
{
   _slotMachine->stopReels();
}
