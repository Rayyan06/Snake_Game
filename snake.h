#ifndef SNAKE_H
#define SNAKE_H

#include "Point.h"
#include "snakegame.h"
#include "Apple.h"


class Snake
{
public:
    enum class Direction 
    {
        right, 
        left, 
        up,
        down
    }
private:
    uint8_t m_length{3}; // Between 0 and 64

    // The snake can never be longer than the size of the grid squared.
    Point m_body[Constants::size*Constants::size];

    // We can use auto because it will infer the types.
    auto m_direction{ Direction::right };
    auto m_prevdir{ Direction::right }

public:
    // Constructor
    Snake(uint8_t length = 3);

    void begin();

    // getter for length
    uint8_t length() const { return m_length }; 

    void render() const;

    // Add a Point
    void push(const Point& p); 

    // Shift all the elements in the array one index backward
    void shift();

    // Remove a point from the end of the array (returns Point)
    Point pop();

    // We need apple because we need to know if we are colliding with it.
    void update(const Point& apple); 

    // Set direction, to be used by joystick
    void setDirection(Snake::Direction dir);

    void handleJoystickInput(int x, int y);

    // bool checkWallCollision();

    // bool checkSelfCollision();

    // bool checkCollision();


    // Returns the position of the next head based on the m_direction
    Point getNextHead();
    
};
#endif