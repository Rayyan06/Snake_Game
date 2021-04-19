#include "Apple.h"
#include "snakegame.h"

bool Apple::isTouching (const Point& other) const 
{
    return ( m_x==other.m_x ) && (m_y == other.m_y);
}

Apple::Apple()
{
    randomSeed(analogRead(3));
}

void Apple::spawn(const Snake& snake)
{
    // Check for snake position later
    m_x = random(Constants::size);
    m_y = random(Constants::size);
}


void Apple::display(uint8_t* screen)
{
    bitSet(screen[m_y], m_x);
}


