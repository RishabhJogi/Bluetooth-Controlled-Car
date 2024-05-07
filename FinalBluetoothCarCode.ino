#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int val;
int Speed = 255;

void setup() {
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}
void loop() {
  if (Serial.available() > 0) {
    val = Serial.read();

    Stop(); //initialize with motors stoped

    // condition for forward direction
    if (val == 'F') {
      forward();
    }

    // condition for backward direction
    if (val == 'B') {
      backward();
    }

    // condition for right direction
    if(val == 'R')
    {
      right();
    }

    // condition for left direction
    if(val == 'L')
    {
      left();
    }
  }
}
// implementing all direction function.
void forward() {
  motor1.setSpeed(Speed);  //Define maximum velocity
  motor1.run(FORWARD);     //rotate the motor clockwise
  motor2.setSpeed(Speed);  //Define maximum velocity
  motor2.run(FORWARD);     //rotate the motor clockwise
  motor3.setSpeed(Speed);  //Define maximum velocity
  motor3.run(FORWARD);     //rotate the motor clockwise
  motor4.setSpeed(Speed);  //Define maximum velocity
  motor4.run(FORWARD);     //rotate the motor clockwise
}

void backward() {
  motor1.setSpeed(Speed);  //Define maximum velocity
  motor1.run(BACKWARD);    //rotate the motor clockwise
  motor2.setSpeed(Speed);  //Define maximum velocity
  motor2.run(BACKWARD);    //rotate the motor clockwise
  motor3.setSpeed(Speed);  //Define maximum velocity
  motor3.run(BACKWARD);    //rotate the motor clockwise
  motor4.setSpeed(Speed);  //Define maximum velocity
  motor4.run(BACKWARD);    //rotate the motor clockwise
}

void left()
{
  motor1.setSpeed(Speed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(Speed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(Speed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speed); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0);  //Define maximum velocity
  motor1.run(RELEASE);    //rotate the motor clockwise
  motor2.setSpeed(0);  //Define maximum velocity
  motor2.run(RELEASE);    //rotate the motor clockwise
  motor3.setSpeed(0);  //Define maximum velocity
  motor3.run(RELEASE);    //rotate the motor clockwise
  motor4.setSpeed(0);  //Define maximum velocity
  motor4.run(RELEASE);    //rotate the motor clockwise
}
