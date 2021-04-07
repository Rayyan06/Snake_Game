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
char dir{ 'r' };

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



int snake[50][2] = {{3, 3}, {3, 4}, {3, 5}};


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

void displayDot(int x, int y)
{
  bitSet(screen[y], x);
}

int snakeLength()
{
  return sizeof(snake) / sizeof(snake[0]);
}
void renderSnake()
{
  for (int i = 0; i < snakeLength(); i++) {
    displayDot(snake[i][0], snake[i][1]);
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
  
  if (x_val < 400) dir = 'l';
  else if (x_val > 800) dir = 'r';
  if (y_val < 400) dir = 'd';
  else if (y_val > 800) dir = 'u';
  
}
void moveSnake()
{
  int head[2] = {snake[0][0], snake[0][1]};
  //Serial.println(head[0]); 
  
  int newHead[2];
  if (dir=='r') {
    newHead[0] = head[0] + 1;
    newHead[1] = head[1];
  }
  else if (dir=='l') {
    newHead[0] = head[0] - 1;
    newHead[1] = head[1];
  }
  else if (dir=='u') {
    newHead[0] = head[0];
    newHead[1] = head[1] - 1;
  }
  else if (dir=='d') {
    newHead[0] = head[0];
    newHead[1] = head[1] + 1;
  }
  snake[0][0] = newHead[0];
  snake[0][1] = newHead[1];

  snake[snakeLength()][0] = 0;
  
  for (int i = 0; i < snakeLength(); i ++) 
  {
    snake[i] = snake[i + 1]
  }
  
  
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
