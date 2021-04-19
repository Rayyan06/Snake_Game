#ifndef SNAKE_H
#define SNAKE_H

#include "snakegame.h"
#include "Apple.h"
#include <Arduino.h>
#include "Point.h"

class Point;
class Snake
{
public:
    enum class Direction 
    {
        right, 
        left, 
        up,
        down
    };
private:
    uint8_t m_length{3}; // Between 0 and 64

    // The snake can never be longer than the size of the grid squared.
    Point m_body[64] = {Point{3, 4}, Point{3, 5}, Point{3, 6}};

    // We can use auto because it will infer the types.
    Snake::Direction m_direction{ Snake::Direction::right };
    Snake::Direction m_prevdir{ Snake::Direction::right };

public:
    // Constructor
    Snake(uint8_t length = 3);

    void begin();

    // getter for length
    uint8_t length() const { return m_length; }

    void render() const;

    // Add a Point
    void push(const Point& p); 

    // Shift all the elements in the array one index backward
    void shift();

    // Remove a point from the end of the array (returns Point)
    Point& pop();

    // We need apple because we need to know if we are colliding with it.
    void update(Apple& apple); 

    // Set direction, to be used by joystick
    void setDirection(Snake::Direction dir);

    void handleJoystickInput(int x, int y);

    // bool checkWallCollision();

    // bool checkSelfCollision();

    // bool checkCollision();


    // Returns the position of the next head based on the m_direction
    Point getNextHead() const;
    
};
#endif