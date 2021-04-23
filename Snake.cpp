#include "Snake.h"
#include <Arduino.h>


Snake::Snake()
{
    // Initialize our body with segments
    m_body[0] = { 2, 3 };
    m_body[1] = { 3, 3 };
    m_body[2] = { 4, 3 };
}
Snake::display() const 
{
    for (uint8_t i{ 0 }; i < m_length; ++i)
    {
        m_body[i].display(); // using .display() method on Point
    }
}

