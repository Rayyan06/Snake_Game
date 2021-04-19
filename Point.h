#ifndef POINT_H
#define POINT_H

// for declaring Point::getNextHead as friend
#include "snake.h" 
#include "Apple.h"
#include <Arduino.h>


class Point
{
private:
    uint8_t m_x;
    uint8_t m_y;
public:
    // We need a sensible empty constructor because we will be using it in the array
    Point() = default; 
    Point(uint8_t x, uint8_t y);

    bool isTouching(const Point& other) const;

    void display() const;
    
    // friend Point Snake::getNextHead() const;
    friend class Snake; // Make this member function friend later
    friend class Apple;


};

#endif