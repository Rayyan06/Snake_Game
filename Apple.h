#ifndef APPLE_H
#define APPLE_H

// #include "Point.h"// When I learn inheritance


class Snake;

class Apple
{
private:
    uint8_t m_x;
    uint8_t m_y;
public:

    Apple() = default; 
    Apple(uint8_t x, uint8_t y)
    : m_x{ x }, m_y{ y }
    {

    }


    bool isTouching(const Point& other) const;

    void spawn(const Snake& snake);
    void display() const;
    
    
}