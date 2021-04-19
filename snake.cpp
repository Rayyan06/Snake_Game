#include "snake.h"
#include <Arduino.h>
#include "Apple.h"
#include "Point.h"

Snake::Snake(uint8_t length) : m_length{ length }
{};


void Snake::begin()
{
    m_body[0] = Point{ 3, 4 };
    m_body[1] = Point{ 3, 5 };
    m_body[2] = Point{ 3, 6 };
}

void Snake::render() const
{  
    // So Simple.
    for (int i{ 0 }; i < m_length; ++i)
    {
        m_body[i].display();
    }
}


void Snake::shift()
{
    for (size_t i{ 0 }; i < m_length; ++i)
    {
        m_body[i + 1] = m_body[i];
    }
}

void Snake::push(const Point& p)
{
    // First, we shift. To make sure there is space for the new point
    shift();
    // Then, We add the new point to the beginning of the array
    m_body[0] = p;

    // And we increment the length
    ++m_length;
}


Point& Snake::pop()
{
    // We can just return the last value in the array and then decrement the length; We don't care about the garbage past m_length

    /*
    This is equavelent to:

    Point p{ m_body[m_length ]}
    --m_length;
    return p;

    */
    return m_body[--m_length];
}


// Returns a new point given m_direction (return by value)
Point Snake::getNextHead() const
{
    Point newHead{ m_body[0] };
    switch(m_direction)
    {
        case Snake::Direction::right:
            newHead.m_x += 1;
        case Snake::Direction::left:
            newHead.m_x -= 1;
        case Snake::Direction::up:
            newHead.m_y += 1;
        case Snake::Direction::down:
            newHead.m_y -= 1;
        
    }
    return newHead;
}

void Snake::update(Apple& apple)
{
    Point newHead { getNextHead() };
    
    // Check for collisions 
    // checkCollisions();

    push(newHead);

    if (!apple.isTouching(newHead))
        pop(); // Pop the tail if the apple isn't touching the newHead
    else
        apple.spawn(*this); // Move the apple
    
}


void Snake::setDirection(Snake::Direction dir)
{
    using direction = Snake::Direction;

    // Check for invalid directions. ( up and then down, left and then right etc...)
    if (
        (
            (dir == direction::right)
            && (m_prevdir == direction::left)
        ) 
        || 
        (
            (dir == direction::up)
            && (m_prevdir == direction::down)
        )
        || 
        (
            (dir == direction::left)
            && (m_prevdir == direction::right)
        )
        ||
        (
            (dir == direction::down)
            && (m_prevdir == direction::up)
        )
    )
    {
        return;
    }

    m_prevdir = m_direction; // save m_direction state
    m_direction = dir; // give m_direction new state.
    

}

void Snake::handleJoystickInput(int x, int y)
{
    if (x < JoystickControl::sensitivity) setDirection(Snake::Direction::left);
    else if (x > (1023 - JoystickControl::sensitivity)) setDirection(Snake::Direction::right);

    if (y < JoystickControl::sensitivity) setDirection(Snake::Direction::down);
    else if (y > (1023 - JoystickControl::sensitivity)) setDirection(Snake::Direction::up);
}