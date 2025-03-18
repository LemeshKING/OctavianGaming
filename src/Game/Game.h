#include "../Button/StartButton.h"
#include "../Button/StopButton.h"
#include "../Render/Render.h"
#include "../SlotMachine/SlotMachine.h"
#include "../StateMachine/StateMachine.h"
#include "../InputHandler/InputHandler.h"
#include "../StateMachine/IdleState.h"
#include "../StateMachine/SpinningState.h"
#include "../StateMachine/ResultState.h"

typedef std::unique_ptr<Button> UPtrButton;


class Game
{
private:
      StateMachine stateMachine;
      SlotMachine slotMachine;
      Render render;
      InputHandler inputHandler;
      UPtrButton starButton;
      UPtrButton stopButton;
      SPtrState idleState = std::make_shared<IdleState>();
      SPtrState spinningState = std::make_shared<SpinningState>(slotMachine);
      SPtrState resultState = std::make_shared<ResultState>(slotMachine);

   
public:
   Game();
   void run();
};

