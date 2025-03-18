#include "ResultState.h"

ResultState::ResultState(SlotMachine& slotMachine)
{
   _slotMachine = &slotMachine;
}

void ResultState::enter()
{
   //������ ����� � ���������
}

void ResultState::update()
{
   if(_slotMachine->stopReels())
      _slotMachine->getResult();
}

void ResultState::exit()
{
   //������ ������ �� ���������
}
