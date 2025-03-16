#include "State.h"
#include<memory>

class StateMachine
{
 private:
   std::shared_ptr<State> currentState;
 public:
   void changeState();
   void update();
};