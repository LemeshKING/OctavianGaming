#include "StateMachine.h"

void StateMachine::changeState()
{
   //������������ ���������
}

void StateMachine::update()
{
   currentState->update();
}
