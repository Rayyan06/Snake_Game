
/*
	Snake_Game
	This is a Snake Game in arduino which you control using a joystick and has an 8x8 Led display. 
	The circuit:
	* JOYSTICK - connected to pins 0, 1, and 2 
	* MAX72XX  - connected to pins 12, 10, 11, and 1.
     
    The Code:
    * Snake class - Snake.h
    * Point class
	Created 17 April 2021
	By Rayyan Khan
	Modified 21 April 21
	By Rayyan Khan
*/


#include <Arduino.h>
#include <LedControl.h>
#include "SnakeGame.h"
#include "Snake.h"


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



// An array of bytes to output to the MAX display
Screen_t Screen[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};

// This is a utility function for displaying a single bit on the screen.
void DisplayDot(Screen_t x, Screen_t y, bool state)
{
  // lc.setLed(addr, row, col, state)
  lc.setLed(1, x, y, state);
}


// This function displays the entire screen
void DisplayScreen()
{
  for (Screen_t x=0; x < 8; ++x)
  {
    Screen_t data = &Screen[x];
    for (Screen_t y=0; y < 8; ++y)
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

  
  Snake snake{};


  
  for (; ;) 
  {
    snake.display(Screen);
    snake.update();
    DisplayScreen();
    lc.clearDisplay(0);
    
  }
  // Execution will never get here(unless we break or something lol)
}