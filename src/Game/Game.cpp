#include "Game.h"

Game::Game()
{
// инициализируем начально состояние, создаем кнопки.
   starButton = std::make_unique<StarButton>();
   stopButton = std::make_unique<StopButton>();
   std::shared_ptr<ResultState> tmp1 = std::make_shared<ResultState>(*slotMachine);
   tmp1->Attach(tmp);
   resultState = tmp1;
   stateMachine.changeState(idleState);
   

}

void Game::run()
{

   sf::Clock clock;  
   sf::Clock clock1;  
   float time;
   float time2;
   sf::RenderWindow& window = render.getWindow();
   while (window.isOpen()) 
   {
      if(stateMachine.getState() == idleState)
         clock.restart();
      time = clock.getElapsedTime().asSeconds();
      if(stateMachine.getState() != spinningState)
         clock1.restart();
      time2 = clock1.getElapsedTime().asSeconds();
      sf::Event event;
      while (window.pollEvent(event)) 
      {
      
         if (event.type == sf::Event::Closed)
            window.close();

      }

         if (event.type == sf::Event::MouseButtonPressed) 
            if (event.mouseButton.button == sf::Mouse::Left) 
               if(inputHandler.isButtonPresset(starButton, sf::Mouse::getPosition(window)) && stateMachine.getState() == idleState)
               {
                  countMatches = 0;
                  starButton->onButtonClick();
                  stateMachine.changeState(spinningState);
               }
               else if(inputHandler.isButtonPresset(stopButton, sf::Mouse::getPosition(window)) && stateMachine.getState() == spinningState && time > 1)
               {
                  stopButton->onButtonClick();
                  stateMachine.changeState(resultState);
                  clock.restart();
                  time = 0;
               }
            
         
      
      if (time2 > 3)
      {
         time2 = 0;
         stateMachine.changeState(resultState);
      }
      stateMachine.update();

      window.clear(sf::Color::White);
      if(stateMachine.getState() != spinningState)
         render.drawResult(countMatches);
      render.drawReels(*slotMachine);
      render.drawButton(starButton);
      render.drawButton(stopButton);


      window.display();
   }
}



void Game::resultOver()
{
   stateMachine.changeState(idleState);
}

ResultStateObserver::ResultStateObserver(StateMachine& stateMachine, SPtrState &idleState)
{
   _stateMachine = &stateMachine;
   _idleState = idleState;
}

void ResultStateObserver::resultOver(int& count)
{
   _stateMachine->changeState(_idleState);
   Game::countMatches = count;
}

int Game::countMatches = 0;