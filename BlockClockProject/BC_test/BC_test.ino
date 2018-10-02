/*
    BLock Clock Test Program
    March 31, 2018
*/

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

#include "BC.h"

int Xdelay = 500;
int Ydelay = 500;
bool X = true; //
bool FWD = true;

#include <SPI.h>
#include <SparkFunDS3234RTC.h>

//#include <Servo.h>
//Servo myservo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  Serial << "Block Clock Tester\n";
  Serial.setTimeout(1000000L);
  pinMode(nCOIL_SS, OUTPUT);
  digitalWrite(nCOIL_SS, HIGH);
  
  rtc.begin(nCLK_SS);

  rtc.update();
  printTime();
//  pinMode(CLAW_MTR, OUTPUT);
//  digitalWrite(CLAW_MTR, LOW);
//  pinMode(CLAW_UP, INPUT_PULLUP);
//  pinMode(CLAW_DOWN, INPUT_PULLUP);

//  myservo.attach(6);
  
  printHelp();
}

void loop()
{

  char c = Serial.read();
  switch (c)
  {
    case 'D' : set_time(); break;
    case 'H' : set_HMS(); break;
    case 'T' : rtc.update();  printTime(); break;
       
    case 'F' : FWD = true; break;

    case 'R' : FWD = false; break;

    case 'u' :  SLCC_hand_up(); break;

    case 'd' : SLCC_hand_down(); break;

    case 'B' : SLCC_hand_grasp(); break;
    case 'b' : SLCC_hand_release(); break;

    case 'X' : X = true; break;
    case 'Y' : X = false; break;

    case 'S' : stepto(); break;
    case 'G' : goto_step(); break;

    default: if (c != -1) printHelp();
  }
}

void printHelp()
{
  Serial << "Enter one of the following:\n"
         << "   D - to set the time\n"
         << "   H - to set HMS\n"
         << "   T - view time\n"
         << "   F - step direction forward\n"
         << "   R - step direction reverse\n"
         << "   u - hand up\n"
         << "   d - hand down\n"
         << "   B - grasp block\n"
         << "   b - release block\n"
         << "   X - step axis X\n"
         << "   Y - step axis Y\n";
}


