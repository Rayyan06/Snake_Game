#include "Snake.h"
#include <Arduino.h>
#include "SnakeGame.h" // for Screen_t
#include "Point.h" // for specifying Point as a return type for .pop()

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
    m_body[++m_length] = p;

}



// We return by value to avoid a dangling reference
Point Snake::pop()
{
    Point popped_of_segment = m_body[0]; // This will be popped off in the loop below
    /* Left shifts the entire array */
    for (length_t i{ 0 }; i < m_length; ++i)
    {
        m_body[i] = m_body[i + 1];
    }

    --m_length; // Decrement m_length

    return popped_of_segment;
}

Point Snake::getNextHead() const
{
    // DON'T define by reference, 
    auto head{ m_body[m_length] };

    using dir = Snake::Dir;

    switch(m_direction)
    {
        case dir::right:
            ++head.x;
            break;
        case dir::left:
            --head.x;
            break;
        case dir::up:
            --head.y;
            breal
        case dir::down:
            ++head.y;
            break;
            
    }
    
    return head;
}

Snake::update()
{

    push(getNextHead());
    pop();
}

