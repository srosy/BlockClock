/*
   Project Block Clock
   Author: Spencer Rosenvall
   Date: 4/3/2018
*/

#include <SPI.h>
#include <SparkFunDS3234RTC.h>
#include "BC.h"
#define verbose_ false
void setup()
{
  Serial.begin(9600);
  Serial << "Block Clock\n";
  Serial.setTimeout(1000000L);
  // initializeClock();
  initializeBlocks();
  checkBlockCounts();
  
  printTimeBlocks();
  printIdleBlocks();
}

void loop()  // interactive test
{
//  getTime();
//  chkTime();
//  printTimeBlocks();
//  printIdleBlocks();

goToLocation( 1500,  1500);
goToLocation( -1500,  -1500);
}

//void loop()  // tests all possible times
//{
//  for (H = 1; H <= 12; H++)
//  {
//    for (M = 0; M <= 59; M++)
//    {
//      //Serial << H << ":" << M << "\n";
//      chkTime();
//      isTimeRight();
//      checkBlockCounts();
//    }
//  }
//  H = 1;  // got to check rollover from 12:59 to 1:00
//  M = 0;
//  chkTime();
//  isTimeRight();
//  checkBlockCounts();
//
//  Serial << "All possible times are correct and no blocks were lost\nThis is the final state of the blocks\n";
//  printTimeBlocks();
//  printIdleBlocks();
//  while (true);
//}

void isTimeRight()
{
  int T[4];
  T[0] = H / 10;
  T[1] = H % 10;
  T[2] = M / 10;
  T[3] = M % 10; // T has time by digit
  Serial << T[0] << T[1] << ":" << T[2] << T[3] << "\n";

  for (int i = 0; i < 4; i++)
    if (T[i] != time_b[i].v)
    {
      Serial << "bad time check\n";
      Serial << H << ":" << M << "\n";
      while (true);
    }
}





