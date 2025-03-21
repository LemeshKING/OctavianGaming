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
   {
      _count = _slotMachine->getResult();
      Notify();
   }
}

void ResultState::exit()
{
   //логика выхода из состо€ни€
}

void ResultState::Attach(SPtrObserver& observer)
{
   _observer = observer;
}

void ResultState::Detach(SPtrObserver& observer)
{
   _observer.reset();
}

void ResultState::Notify()
{
   _observer->resultOver(_count);
}
