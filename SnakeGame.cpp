#include <Arduino.h>
#include <LedControl.h>
#include "SnakeGame.h"


/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(
  PINS::LED::DIN,
  PINS::LED::LOAD,
  PINS::LED::CLK,
  1
);

uint8_t Screen[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};

void DisplayDot(uint8_t x, uint8_t y, bool state)
{
  // lc.setLed(addr, row, col, state)
  lc.setLed(1, x, y, state);
}


void DisplayScreen()
{
  for (uint8_t x=0; x < 8; ++x)
  {
    uint8_t data = &Screen[x];
    for (uint8_t y=0; y < 8; ++y)
    {
      // let data = 0b00001000
      // Now 1<<y is 0b00001000
      // same thing as Screen[y], but more effocoemt
      if (data & (1 << y))
      {
        DisplayDot(x, y, 1);
      } 
      else 
      {
        DisplayDot(x, y, 0);
      }
    }
  }
}



int main()
{
  init();
  
  
 /*
  The MAX72XX is in power-saving mode on startup,
  we have to do a wakeup call
 */
  lc.shutdown(0,false);
  /* Set the brightness to a medium value */
  lc.setIntensity(0, CONSTANTS::BRIGHTNESS);
  /* and clear the display */
  lc.clearDisplay(0);


  
  for (; ;) 
  {
    DisplayScreen();
    lc.clearDisplay(0);
    
  }
}