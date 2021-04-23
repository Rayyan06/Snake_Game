#ifndef POINT_H
#define POINT_H
#include <Arduino.h>
#include "SnakeGame.h" // for Screen_t

class Point
{
private:
    Screen_t m_x;
    Screen_t m_y;
public:
    // We need a default constructor because our Points will be initialized in an array( the snake's body )
    Point() = default;
    Point(Screen_t x, Screen_t y);

    // We need an isTouching method on point for two reasons:
    // 1. To check if the Snake has collided with itself.
    // 2. To check if the Snake has collided with an Apple.
    bool isTouching(const Point& other) const;

    // Make this const because we are not changing anything except the Screen itself
    void display(Screen_t (&Screen)[8]) const;



};

#endif

