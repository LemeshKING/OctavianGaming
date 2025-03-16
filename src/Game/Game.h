#include "../Button/StartButton.h"
#include "../Button/StopButton.h"
#include "../Render/Render.h"
#include "../SlotMachine/SlotMachine.h"
#include "../StateMachine/StateMachine.h"
#include "../InputHandler/InputHandler.h"

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

   
public:
   Game();
   void run();
};

