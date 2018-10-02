void set_time()
{
  // Or you can use the rtc.setTime(s, m, h, day, date, month, year)
  // function to explicitly set the time:
  // e.g. 7:32:16 | Monday October 31, 2016:
  //rtc.setTime(16, 32, 7, 2, 31, 10, 16);  // Uncomment to manually set time
  Serial << "Enter year:";
  year = Serial.parseInt();

  Serial << "\nEnter month:";
  month = Serial.parseInt();

  Serial << "\nEnter day:";
  date = Serial.parseInt();

  set_HMS();
}

void set_HMS()
{
  Serial << "\nEnter hour:";
  hour = Serial.parseInt();

  Serial << "\nEnter minute:";
  minute = Serial.parseInt();

  Serial << "\nEnter second:";
  second = Serial.parseInt();
  day = 2;
  rtc.setTime(second, minute, hour, day, date, month, year);
  rtc.update();
  Serial << "\nTime set\n";
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
    if (rtc.pm()) Serial.print(" PM "); // Returns true if PM
    else Serial.print(" AM ");
  }

  // Serial.print(" | ");

  // Few options for printing the day, pick one:
  //Serial.print(rtc.dayStr()); // Print day string
  //Serial.print(rtc.dayC()); // Print day character
  //Serial.print(rtc.day()); // Print day integer (1-7, Sun-Sat)
  Serial.print(" - ");
  Serial.print(String(rtc.month()) + "/" +   // Print month
               String(rtc.date()) + "/");  // Print date
  Serial.println(String(rtc.year()));        // Print year
}
