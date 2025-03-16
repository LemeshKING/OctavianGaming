#include "State.h"

class IdleState : public State
{

   void enter() override final;
   void update() override final;
   void exit() override final;
};