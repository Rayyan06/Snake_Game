#ifndef POINT_H
#define POINT_H
#include <Arduino.h>


class Point
{
private:
    uint8_t m_x;
    uint8_t m_y;
public:
    // We need a default constructor because our Points will be initialized in an array( the snake's body )
    Point() = default;
    Point(uint8_t x, uint8_t y);

    // We need an isTouching method on point for two reasons:
    // 1. To check if the Snake has collided with itself.
    // 2. To check if the Snake has collided with an Apple.
    bool isTouching(const Point& other) const;

    // Make this const because we are not changing anything
    void display(uint8_t (&Screen)[8]) const;



};

#endif

