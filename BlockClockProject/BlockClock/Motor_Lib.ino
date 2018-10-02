void Xstep(bool fwd)
{
  digitalWrite(DIR_X, fwd); // set direction
  digitalWrite(STEP_X, HIGH);
  digitalWrite(STEP_X, LOW);
  delayMicroseconds(xDelay); // determine best delay, see BC.h to change delay
}

void Ystep(bool fwd)
{
  digitalWrite(DIR_Y, fwd);
  digitalWrite(STEP_Y, HIGH);
  digitalWrite(STEP_Y, LOW);
  delayMicroseconds(yDelay);
}

void goToLocation(int x, int y)
{
  bool fwd = true;
  int steps;
  //int steps = getstep();


  steps = x; // get x coordinate
  if (steps < 0)
  {
    steps = - steps;
    fwd = false;
  }
  for (int i = 0; i < steps; i++)Xstep(fwd);

  steps = y; // get y coordinate
  if (steps < 0)
  {
    steps = - steps;
    fwd = false;
  }
  for (int i = 0; i < steps; i++)Ystep(fwd);
}

int getstep()
{
  Serial.print(" Enter number of steps: ");
  Serial.println();
  return Serial.parseInt(); // return value inputted by user
}

int getBlock_X(block b)
{
  // generate number of steps until at idle_b[i].x
  return b.x;
}

int getBlock_Y(block b)
{
  // generate number of steps until at whatever_block[i].y
  return b.y;
}


