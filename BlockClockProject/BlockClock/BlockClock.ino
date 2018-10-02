/*
   Project Block Clock
   Author: Spencer Rosenvall
   Date: 4/3/2018
*/

#include <SPI.h>
#include <SparkFunDS3234RTC.h>
#include "BC.h"

void setup() 
{
  Serial.begin(9600);
  initializeClock();
  initializeBlocks();
}

void loop() 
{
  getTime();
}








