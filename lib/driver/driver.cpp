#include "driver.h"
#include "Arduino.h"

int leftMotorSpeeed = 6;
int leftRotationOne = A0;
int leftRotationTwo = A5;

int RightMotorSpeeed = 2;
int RightRotationOne = 3;
int RightRotationTwo = 5;

void Vroom::Left()
{
  analogWrite(leftMotorSpeeed, 255);
  analogWrite(RightMotorSpeeed, 100);
};

void Vroom::Right()
{
  analogWrite(RightMotorSpeeed, 255);
  analogWrite(leftMotorSpeeed, 100);
};

void Vroom::Forward()
{
  analogWrite(RightMotorSpeeed, 255);
  analogWrite(leftMotorSpeeed, 255);
  digitalWrite(leftRotationOne, HIGH);
  digitalWrite(leftRotationTwo, LOW);
  digitalWrite(RightRotationOne, HIGH);
  digitalWrite(RightRotationTwo, LOW);
};

void Vroom::BackWard()
{
  analogWrite(RightMotorSpeeed, 255);
  analogWrite(leftMotorSpeeed, 255);
  digitalWrite(leftRotationOne, LOW);
  digitalWrite(leftRotationTwo, HIGH);
  digitalWrite(RightRotationOne, LOW);
  digitalWrite(RightRotationTwo, HIGH);
};

void Vroom::Stop(){
  analogWrite(RightMotorSpeeed, 0);
  analogWrite(leftMotorSpeeed, 0);
}
