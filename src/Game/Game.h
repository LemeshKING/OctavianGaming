#include "../Button/StartButton.h"
#include "../Button/StopButton.h"
#include "../Render/Render.h"
#include "../SlotMachine/SlotMachine.h"
#include "../StateMachine/StateMachine.h"
#include "../InputHandler/InputHandler.h"
#include "../StateMachine/IdleState.h"
#include "../StateMachine/SpinningState.h"
#include "../StateMachine/ResultState.h"
#include "../StateMachine/IObserver.h"
#include "../TextureManager/TextureManager.h"


typedef std::unique_ptr<Button> UPtrButton;



class ResultStateObserver : public IObserver
{
   SPtrState _idleState;
   StateMachine* _stateMachine;
public:
   ResultStateObserver(StateMachine& stateMachine, SPtrState &idleState);
   void resultOver(int &count) override;
};

class Game 
{
private:
      TextureManager textureManager;
      StateMachine stateMachine;
      SlotMachine *slotMachine = new SlotMachine(textureManager);
      Render render;
      InputHandler inputHandler;
      UPtrButton starButton;
      UPtrButton stopButton;
      SPtrState idleState = std::make_shared<IdleState>();
      SPtrState spinningState = std::make_shared<SpinningState>(*slotMachine);
      SPtrState resultState = std::make_shared<ResultState>(*slotMachine);
      SPtrObserver tmp = std::make_shared<ResultStateObserver>(stateMachine, idleState);

   
public:
   Game();
   void run();
   void resultOver();
   static int countMatches;
};


