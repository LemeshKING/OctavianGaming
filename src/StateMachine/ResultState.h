#include "State.h"
#include "ISubject.h"


class ResultState : public State, public ISubject
{
 private:
   SlotMachine *_slotMachine;
   SPtrObserver _observer;
   int _count;
 public:
   ResultState(SlotMachine &slotMachine);
   void enter() override final;
   void update() override final;
   void exit() override final;
   void Attach(SPtrObserver& observer) override final;
   void Detach(SPtrObserver& observer) override final;
   void Notify() override final;
};