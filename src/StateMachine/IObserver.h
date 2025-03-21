#pragma once

class IObserver
{
 public:
   virtual ~IObserver() = default;
   virtual void resultOver(int &count) = 0;
};