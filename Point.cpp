#include "Point.h"
#include "snakegame.h"

Point::Point(uint8_t x, uint8_t y)
    : m_x{ x }, m_y{ y }
    {};

bool Point::isTouching (const Point& other) const 
{
    return ( m_x==other.m_x ) && (m_y == other.m_y);
}


void display(byte[Constants::size]& screen) const
{
    bitSet(screen[m_y], m_x);
}


