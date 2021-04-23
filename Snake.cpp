#include "Snake.h"
#include <Arduino.h>
#include "SnakeGame.h" // for Screen_t


Snake::Snake()
{
    // Initialize our body with segments
    m_body[0] = { 2, 3 };
    m_body[1] = { 3, 3 };
    m_body[2] = { 4, 3 };
}
void Snake::display( Screen_t (&Screen) [8]) const 
{
    for (length_t i{ 0 }; i < m_length; ++i)
    {
        m_body[i].display(Screen); // using .display() method on Point
    }
}


void Snake::push(const Point& p)
{

    /*     This function pushes a Point in front of our body array and 
    increments m_length by 1.
    */
    m_body[m_length++] = p;


}


