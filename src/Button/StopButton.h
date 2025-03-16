#include "Button.h"

class StopButton : public Button
{
 public:
   StopButton();
   void onButtonClick() override final;
};