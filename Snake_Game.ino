//www.elegoo.com
//2016.12.9

//We always have to include the library
#include "LedControl.h"


/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

unsigned int joystickDelay {50};
unsigned long lastMillis;
/*
 * Direction the snake is moving
 * r - right
 * d - down
 * l - left
 * u - up
 */
enum class Direction
{
  dir_right,
  dir_left,
  dir_up, 
  dir_down
};

const int lcSize {8};

byte screen[lcSize] 
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};



struct Point {
  uint8_t x;
  uint8_t y;
};

struct Snake {
  Point body[50];
  Direction dir;
  uint16_t len;
};


Snake snake{ {Point{3, 3}, Point{3, 4}, Point{3, 5}}, Direction::dir_right, 3};

//Snake snake{};
//snake.color = 3;



void setup() {

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
   
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 2);
  /* and clear the display */
  lc.clearDisplay(0);
}

void displayDot(Point point)
{
  bitSet(screen[point.y], point.x);
}


int snakeLength()
{
  return sizeof(snake.body) / sizeof(snake.body[0]);
}

void renderSnake()
{
  for (int i = 0; i < snakeLength(); i++) {
    Serial.print(snake.body[i].x);
    displayDot(snake.body[i]);
  }
}

void displayScreen()
{
  for (int i = 0; i < lcSize; i ++) {
    lc.setRow(0, i, screen[i]);
  }
}

void getJoystickInput() {
  int x_val { analogRead(X_pin) };
  int y_val { analogRead(Y_pin) };
  
  if (x_val < 400) snake.dir = Direction::dir_left;
  else if (x_val > 800) snake.dir = Direction::dir_right;
  if (y_val < 400) snake.dir = Direction::dir_down;
  else if (y_val > 800) snake.dir = Direction::dir_up;
  
}
void moveSnake()
{
  Point head {snake.body[0]};
  //Serial.println(head[0]); 
  
  Point newHead;
 
  switch(snake.dir) {
    case Direction::dir_right:
      newHead.x = head.x + 1;
      newHead.y = head.y;
      break;

    case Direction::dir_left:
      newHead.x = head.x - 1;
      newHead.y = head.y;
      break;
      
    case Direction::dir_up: 
      newHead.x = head.x;
      newHead.y = head.y - 1;
      break;
      
    case Direction::dir_down:
      newHead.x = head.x;
      newHead.y = head.y + 1;
      break;
   
  }
  snake.body[0] = newHead;


  
}

void shiftSnake() {
  for (int i = 0; i < snakeLength(); ++i) 
  {
    snake.body[i] = snake.body[i + 1];
    
  }
  snake.body[snakeLength() + 1] = {0, 0};
}
void loop() { 
  if (millis() - lastMillis >= 300) {
    lastMillis = millis();
    moveSnake();

  }
  renderSnake();
 displayScreen();
 getJoystickInput();
 delay(joystickDelay);
 lc.clearDisplay(0);

  
}
