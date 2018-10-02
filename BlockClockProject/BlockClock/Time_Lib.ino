void initializeClock() {
  pinMode(nCOIL_SS, OUTPUT);
  digitalWrite(nCOIL_SS, HIGH);
  rtc.begin(nCLK_SS);
  rtc.set12Hour();
  //rtc.setTime(1, 34, 2, 5, 4, 4, 2018);
  rtc.autoTime();
  rtc.update();
  printTime();
}

void printTime()
{
  Serial.print(String(rtc.hour()) + ":"); // Print hour
  if (rtc.minute() < 10)
    Serial.print('0'); // Print leading '0' for minute
  Serial.print(String(rtc.minute()) + ":"); // Print minute
  if (rtc.second() < 10)
    Serial.print('0'); // Print leading '0' for second
  Serial.print(String(rtc.second())); // Print second

  if (rtc.is12Hour()) // If we're in 12-hour mode
  {
    // Use rtc.pm() to read the AM/PM state of the hour
    if (rtc.pm()) Serial.print(" PM \n"); // Returns true if PM
    else Serial.print(" AM \n");
  }
}

void getTime() {
  rtc.update(); // update the time
  if (rtc.second() != lastSecond) {
    lastSecond = rtc.second();
    printTime();
  }

  if (rtc.minute() != lastMinute) {
    switch (rtc.minute()) {
      case (10): {
          changeMinOne = true;
        }
      case (20): {
          changeMinOne = true;
        }
      case (30): {
          changeMinOne = true;
        }
      case (40): {
          changeMinOne = true;
        }
      case (50): {
          changeMinOne = true;
        }
      case (60): {
          changeMinOne = true;
        }
      default: changeMinOne = false;
    }
    changeMinTwo = !changeMinTwo; // set to true because minute changed, when block is placed, set to false.
    Serial.println("Minute changed");
    lastMinute = rtc.minute();
  }

  if (rtc.hour() != lastHour) {
    changeHourOne = !changeHourTwo;
    Serial.println("Hour changed");
    lastHour = rtc.hour();
  }
}

void moveBlocks(block h1, block h2, block m1, block m2) {

  if (changeHourOne) {
    goToBlock(h1);
    SLCC_hand_grasp();
    goToBlock(findBlock(-1)); // find empty block
    SLCC_hand_release();
    updateBlock(empty, h1); // updates location and value of block, empty is filled now with h1

    // change time_b[0] [H1]:h2:m1:m2
    if (h1.v == 1) {
      // find location block with block.v == 0
      goToBlock(idle_b[findBlock(0)]);
      SLCC_hand_grasp();
      isNowEmpty(idle_b[findBlock(0)]);
      goToBlock(time_b[0]);
      SLCC_hand_release();
      updateBlock(time_b[0], idle_b[findBlock(0)); // old/new
    }
    else {
      // find block with block.v == 1
      goToBlock(findBlock(1));
      SLCC_hand_grasp();
      updateBlock(h1, empty);
      goToBlock(time_b[0]);
      SLCC_hand_release();
    }
  }

  if (changeHourOne) {
    goToBlock(h2);
    SLCC_hand_grasp();
    // goToBlock(findBlock(empty));// TODO: create method to find empty block
    SLCC_hand_release();
    // updateBlockLocation(h2); // TODO, takes a block

    // change time_b[0] [H1]:h2:m1:m2
    if (h1.v == 1) {
      // find location block with block.v == 0
      // goToBlock(findBlock(0)); TODO: findBlock returns a block, '0' == block.v we want.
      SLCC_hand_grasp();
      // empty.x = h1.x; // assign empty x
      // empty.y = h1.y; // assign empty y
      // goToBlock(time_b[0]);
      SLCC_hand_release(),
    }
    else {
      // find block with block.v == 1
      // goToBlock(findBlock(1));
      SLCC_hand_grasp();
      // empty.x = h1.x; // assign empty x
      // empty.y = h1.y; // assign empty y
      // goToBlock(time_b[0]);
      SLCC_hand_release();
    }
  }
}

//if (changeHourTwo) {
//
//}
//
//if (changeMinOne) {
//
//}
//
//if (changeMinTwo) {
//
//}




