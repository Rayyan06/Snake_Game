#include "snake.h"


Snake::Snake(uint8_t length) : m_length{ length }
{};


void Snake::begin()
{
}

void Snake::render() const
{  
    // So Simple.
    for (auto& p: m_body)
    {
        p.display();
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
Point Snake::getNextHead()
{
    Point head{ m_body[0] };
    switch(m_direction)
    {
        case right:
            return { head.m_x + 1, head.m_y };
        case left:
            return { head.m_x - 1, head.m_y };
        case up:
            return { head.m_x, head.m_y + 1};
        case down:
            return { head.m_x, head.m_y - 1};
    }
}

void Snake::update(const Point& apple)
{
    Point& newHead { getNextHead() };
    
    // Check for collisions 
    // checkCollisions();

    push(newHead);

    if (!apple.isTouching(newHead))
        pop(); // Pop the tail if the apple isn't touching the newHead

    
}


void Snake::setDirection(Snake::Direction dir)
{
    using direction = Snake::direction;

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
            && (m_prevdir == up)
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
    if (x_val < JoystickControl::sensitivity) snake.setDirection(Snake::Direction::left);
    else if (x_val > (1023 - JoystickControl::sensitivity)) snake.setDirection(Snake::Direction::right);

    if (y_val < JoystickControl::sensitivity) snake.setDirection(Snake::Direction::down);
    else if (y_val > (1023 - JoystickControl::sensitivity)) snake.setDirection(Snake::Direction::up);
}