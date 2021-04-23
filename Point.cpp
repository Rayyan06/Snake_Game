#include "Point.h"
#include <Arduino.h>

Point::Point(uint8_t x, uint8_t y)
: m_x{ x }, m_y{ y }
{};

bool Point::isTouching( const Point& other ) const 
{
    return (m_x == other.m_x) && (m_y == other.m_y);
}

void Point::display(uint8_t (&Screen)[8]) const
{
    bitSet(Screen[m_y], m_x);
}