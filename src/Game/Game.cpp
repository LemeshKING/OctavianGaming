#include "Game.h"

Game::Game()
{
// инициализируем начально состояние, создаем кнопки.
   starButton = std::make_unique<StarButton>();
   stopButton = std::make_unique<StopButton>();
   stateMachine.changeState(idleState);
}

void Game::run()
{
   sf::RenderWindow& window = render.getWindow();
   while (window.isOpen()) 
   {
      sf::Event event;
      while (window.pollEvent(event)) 
      {
         if (event.type == sf::Event::Closed)
            window.close();
         if (event.type == sf::Event::MouseButtonPressed) 
            if (event.mouseButton.button == sf::Mouse::Left) 
               if(inputHandler.isButtonPresset(starButton, sf::Mouse::getPosition(window)) && stateMachine.getState() == idleState)
               {
                  starButton->onButtonClick();
                  stateMachine.changeState(spinningState);
               }
               else if(inputHandler.isButtonPresset(stopButton, sf::Mouse::getPosition(window)) && stateMachine.getState() == spinningState)
               {
                  stopButton->onButtonClick();
                  stateMachine.changeState(resultState);
               }
            
         
      }
      stateMachine.update();
      window.clear(sf::Color::White);
      render.drawReels(slotMachine);
      render.drawButton(starButton);
      render.drawButton(stopButton);


      window.display();
   }
}
