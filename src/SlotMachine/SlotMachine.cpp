#include "SlotMachine.h"

SlotMachine::SlotMachine()
{
   slotMachineSprite.setPosition(sf::VideoMode::getDesktopMode().width / 5, sf::VideoMode::getDesktopMode().height / 6);
   slotMachineSprite.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.1, sf::VideoMode::getDesktopMode().height / 1.36));
   slotMachineSprite.setFillColor(sf::Color::Magenta);
   slotMachineSprite.setOutlineThickness(2);
   slotMachineSprite.setOutlineColor(sf::Color::Black);
   reels.resize(3);
   for(int i = 0; i < reels.size(); i++)
      reels[i] = Reel(i);
}

void SlotMachine::spinReels()
{
   //������ �������� ������
}

void SlotMachine::stopReels()
{
   //������ ��������� ������
}

void SlotMachine::getResult()
{
   //������ ��������� ����������
}

ReelVector SlotMachine::getReels()
{
    return reels;
}

sf::RectangleShape SlotMachine::getSprite()
{
   return slotMachineSprite;
}
