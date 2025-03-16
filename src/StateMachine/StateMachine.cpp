#include "StateMachine.h"

void StateMachine::changeState()
{
   //переключение состояний
}

void StateMachine::update()
{
   currentState->update();
}
