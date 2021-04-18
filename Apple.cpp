#include "Apple.h"

bool Apple::isTouching (const Point& other) const 
{
    return ( m_x==other.m_x ) && (m_y == other.m_y);
}

Apple::Apple()
{
    randomSeed(analogRead(3));
}

void spawn(const Snake& snake)
{
    // Check for snake position later
    m_x = random(Constants::size);
    m_y = random(Constants::size);
}


void display(byte[Constants::size]& screen) const
{
    bitSet(screen[m_y], m_x);
}


