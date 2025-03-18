#include "State.h"

class SpinningState : public State
{
 private:
    SlotMachine *_slotMachine;
 public:
   SpinningState(SlotMachine& slotMachine);
   void enter() override final;
   void update() override final;
   void exit() override final;
};