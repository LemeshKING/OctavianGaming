#include "Game.h"

Game::Game()
{
// инициализируем начально состояние, создаем кнопки.
   starButton = std::make_unique<StarButton>();
   stopButton = std::make_unique<StopButton>();
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
      }
      window.clear(sf::Color::White);
      render.drawButton(starButton);
      render.drawButton(stopButton);


      window.display();
   }
}
