#include "StateMachine.h"

void StateMachine::changeState(SPtrState& state)
{
   if(currentState != nullptr) currentState->exit();
   currentState = state;
   if(currentState != nullptr) currentState->enter();
}

void StateMachine::update()
{
   currentState->update();
}

SPtrState StateMachine::getState()
{
   return currentState;
}
