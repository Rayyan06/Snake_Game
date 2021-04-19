/*
	Snake_Game

	This is a Snake Game made which you control using a joystick and has an 8x8 Led display. 

	The circuit:
	* JOYSTICK - connected to pins 0, 1, and 2 (see snakegame.h for details) 
	* MAX72XX  - connected to pins 12, 10, 11, and 1.
     
	Created 17 April 2021
	By Rayyan Khan
	Modified 19 April 21
	By Rayyan Khan


*/

//We always have to include the library arduino in .cpp files
#include <Arduino.h> 
#include "LedControl.h"
#include "snakegame.h"
#include "snake.h"


/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(
    LEDConfig::DIN,
    LEDConfig::LOAD,
    LEDConfig::CLK,
    LEDConfig::count
);


unsigned long lastMillis;


uint8_t screen[Constants::size] 
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};



void displayScreen()
{
  for (int i {0}; i < Constants::size; ++i) 
  {
      // We only have one matrix
    lc.setRow(LEDConfig::count - 1, i, screen[i]); 
  }
}



int main() 
{ 

    init(); // initialize timers

    Snake snake{};
    Apple apple{};
    
    snake.begin();
    apple.spawn(snake);
    

    
    pinMode(JoystickControl::SW_PIN, INPUT);
    pinMode(JoystickControl::X_PIN, INPUT);
    pinMode(JoystickControl::Y_PIN, INPUT);

    // SW_PIN is on by default.
    digitalWrite(JoystickControl::SW_PIN, HIGH);

    // Start our serial.
    // Serial.begin(9600);

    /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
   */
    lc.shutdown(0,false);
    /* Set the brightness to a medium value */
    lc.setIntensity(0, Constants::brightness);
    /* and clear the display */
    lc.clearDisplay(0);

    // use serial.flush, otherwise interrupts will be turned off
    // Serial.flush();


    
    for ( ;; )  // infinite loop
    {
        if (millis() - lastMillis >= Constants::snake_delay) {
            lastMillis = millis();
            snake.update(apple);
            
        }
        snake.render();
        apple.display();
        displayScreen();
        auto joystick_x = analogRead(JoystickControl::X_PIN);
        auto joystick_y = analogRead(JoystickControl::Y_PIN);
        snake.handleJoystickInput(joystick_x, joystick_y); 
        delay(Constants::delay);
        lc.clearDisplay(0);
    }

  
}
