#ifndef SNAKEGAME_H
#define SNAKEGAME_H

// Pins for MAX display
namespace LEDConfig 
{

    // DataIN for LedControl
    constexpr int DIN { 12 };

    // Load(CS)
    constexpr int LOAD{ 11 };

    // Clock for Display
    constexpr int CLK{ 10 };

    // Number of Max72Xx's
    constexpr int count{ 1 };

}

namespace Constants
{
    // Delay to prevent screen refreshing too often
    constexpr unsigned int delay{ 50 };

    // Led brightness is currently constant( maybe change later? )
    constexpr unsigned int brightness { 5 };

    // Size of the LED display
    constexpr int size{ 8 };

    // Effectively the speed of the snake.
    constexpr int snake_delay{ 300 };

}


namespace JoystickControl 
{
    // Switch pin for 'clicking' the joystick.
    constexpr int SW_PIN{ 2 }; 

    // Analog pins for x and y axis.
    constexpr int X_PIN{ 0 };
    constexpr int Y_PIN{ 1 };

    // Between 0 and 600
    constexpr int sensitivity{ 400 }; 

}
#endif