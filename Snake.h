#ifndef SNAKE_H
#define SNAKE_H
#include "Point.h"
#include <Arduino.h>
#include "SnakeGame.h"

class Snake
{
public:
    using length_t = uint8_t;
    enum class Dir
    {
        right,
        up,
        down,
        left
    };

private:
    // Snake can never be longer than 64 bits
    length_t m_length{ 3 }; // Initial length
    Point m_body[64];
    Snake::Dir m_direction{ Snake::Dir::right };

public:
    Snake();

    void display(Screen_t (&Screen) [8]) const;


    // Body setters
    void push(const Point& p);
    // Remove a point from the end of the array (returns Point)
    Point pop();

    Point getNextHead() const;
    
    // It is okay to define a getter here in the h file (trivial function)
    length_t getLength() const { return m_length; }

    // Also a simple setter
    void setDirection(Snake::Dir dir) { m_direction = dir; }


    void update();

    
};


#endif