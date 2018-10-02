void setup() {
  pinMode(stp, OUTPUT);
  pinMode(stp2, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(SLEEP, OUTPUT);

  digitalWrite(EN, HIGH);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  digitalWrite(RST, HIGH);
  digitalWrite(SLEEP, HIGH);

  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  Serial.println("Enter number for control option:");
  Serial.println("1. Stepper 1 forward one second.");
  Serial.println("2. Stepper 1 reverse one second.");
  Serial.println("3. Stepper 2 forward one second.");
  Serial.println("4. Stepper 2 reverse one second.");
  Serial.println("5. Stepper 1 step until stopped.");
  Serial.println();
}


//Default microstep mode function
void StepForward()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(EN, LOW);
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for (int x = 1; x < 400; x++) //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp, HIGH); //Trigger one step forward
    //delay(1);
    delayMicroseconds(stepDelay);
    digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
    //delay(1);
    delayMicroseconds(stepDelay);
  }
  digitalWrite(EN, HIGH);
}



//Stepper 1 steps 1 second in reverse
void StepReverse()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(EN, LOW);
  digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
  for (int x = 1; x < 500; x++) //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp, HIGH); //Trigger one step forward
    //delay(1);
    delayMicroseconds(stepDelay);
    digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
    delayMicroseconds(stepDelay);
    //delay(1);
  }
  digitalWrite(EN, HIGH);
}


void StepForward2()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(EN, LOW);
  digitalWrite(dir2, LOW); //Pull direction pin low to move "forward"
  for (int x = 1; x < 500; x++) //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp2, HIGH); //Trigger one step forward
    delayMicroseconds(stepDelay);
    //delay(1);
    digitalWrite(stp2, LOW); //Pull step pin low so it can be triggered again
    delayMicroseconds(stepDelay);
    //delay(1);
  }
  digitalWrite(EN, HIGH);
}


void StepReverse2()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(EN, LOW);
  digitalWrite(dir2, HIGH); //Pull direction pin low to move "forward"
  for (int x = 1; x < 500; x++) //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp2, HIGH); //Trigger one step forward
    delayMicroseconds(stepDelay);
    //delay(1);
    digitalWrite(stp2, LOW); //Pull step pin low so it can be triggered again
    delayMicroseconds(stepDelay);
    //delay(1);
  }
  digitalWrite(EN, HIGH);
}

void stepUntilStopped() {
  digitalWrite(EN, LOW);
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  while (true) {
    if (Serial.available() > 0) { // exit the while loop
      Serial.println("breaking");
      break;
    }
    else { // why does this go slow?
      StepForward();
    }
  }
  digitalWrite(EN, HIGH);
}
