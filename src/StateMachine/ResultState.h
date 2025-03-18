#include "State.h"

class ResultState : public State
{
 private:
   SlotMachine *_slotMachine;
 public:
   ResultState(SlotMachine &slotMachine);
   void enter() override final;
   void update() override final;
   void exit() override final;
};