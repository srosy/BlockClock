/**
   Spencer Rosenvall
   Block Clock Project Code
*/

//Declare pin functions on Arduino
#define stp 3
#define stp2 11
#define dir 2
#define dir2 10
#define MS1 4
#define MS2 5
#define MS3 6
#define EN  7
#define RST 8
#define SLEEP 9
#define stepDelay 500


void loop() {
  char user_input;
  while (Serial.available()) {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    if (user_input == '1')
    {
      StepForward();
    }
    else if (user_input == '3')
    {
      StepForward2();
    }
    else if (user_input == '2')
    {
      StepReverse();
    }
    else if (user_input == '4')
    {
      StepReverse2();
    }
    else if (user_input == '5')
    {
      stepUntilStopped();
    }
  }
}







