#include "State.h"

class SpinningState : public State
{
 public:

   void enter() override final;
   void update() override final;
   void exit() override final;
};