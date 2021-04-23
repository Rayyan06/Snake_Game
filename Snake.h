#ifndef SNAKE_H
#define SNAKE_H
#include "Point.h"
#include <Arduino.h>

class Snake
{
public:
    enum class Dir
    {
        right,
        up,
        down,
        left
    };

private:
    // Snake can never be longer than 64 bits
    uint8_t m_length{ 3 }; // Initial length
    Point m_body[64];
    auto m_direction{ Snake::Dir::right };

public:
    Snake();

    void display() const;


    // Body setters
    void push(const Point& p);
    void shift();
    // Remove a point from the end of the array (returns Point)
    Point& pop();

    
    // It is okay to define a getter here in the h file (trivial function)
    uint8_t getLength() const { return m_length };

    // Also a simple setter
    void setDirection(Snake::Dir dir) { m_direction = dir};


    void update();

    
};


#endif