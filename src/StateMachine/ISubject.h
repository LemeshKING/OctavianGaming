#pragma once
#include "IObserver.h"
#include <memory>

typedef std::shared_ptr<IObserver> SPtrObserver;

class ISubject
{
 public:
   virtual ~ISubject() = default;
   virtual void Attach(SPtrObserver& observer) = 0;
   virtual void Detach(SPtrObserver& observer) = 0;
   virtual void Notify() = 0;
};