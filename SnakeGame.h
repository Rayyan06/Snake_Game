#ifndef SNAKEGAME_H
#define SNAKEGAME_H

using Screen_t = uint8_t;

namespace CONSTANTS
{
  inline constexpr int BRIGHTNESS{ 4 };
  constexpr int SENSITIVITY{ 400 }; // Between 0 and 600
}

namespace PINS
{
  namespace JOYSTICK
  {
    constexpr int SW_PIN{ 2 };
    constexpr int Y_PIN { 1 };
    constexpr int X_PIN { 0 };
  }
  namespace LED
  {
    constexpr int DIN { 12 }; // Data in
    constexpr int LOAD{ 11 };
    constexpr int CLK { 10 }; // Clock
  }
}

#endif