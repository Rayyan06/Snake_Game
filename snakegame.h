#ifndef SNAKEGAME_H
#define SNAKEGAME_H

// Pins for MAX display
namespace LEDConfig 
{

    // DataIN for LedControl
    inline constexpr int DIN { 12 };

    // Load(CS)
    inline constexpr int LOAD{ 11 };

    // Clock for Display
    inline constexpr int CLK{ 10 };

    // Number of Max72Xx's
    inline constexpr int count{ 1 };

}

namespace Constants
{
    // Delay to prevent screen refreshing too often
    inline constexpr unsigned int delay{ 50 };

    // Led brightness is currently constant( maybe change later? )
    inline constexpr unsigned int brightness { 5 };

    // Size of the LED display
    inline constexpr int size{ 8 };

    // Effectively the speed of the snake.
    inline constexpr int snake_delay{ 300 };

}


namespace JoystickControl 
{
    // Switch pin for 'clicking' the joystick.
    inline constexpr int SW_PIN{ 2 }; 

    // Analog pins for x and y axis.
    inline constexpr int X_PIN{ 0 };
    inline constexpr int Y_PIN{ 1 };

    // Between 0 and 600
    inline constexpr int sensitivity{ 400 }; 

}
#endif