#include "State.h"
#include<memory>

typedef std::shared_ptr<State> SPtrState;

class StateMachine
{
 private:
    SPtrState currentState;
 public:
   void changeState(SPtrState &state);
   void update();
   SPtrState getState();
};