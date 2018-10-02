void Xstep(bool fwd)
{
  digitalWrite(DIR_X, fwd);
  digitalWrite(STEP_X, HIGH);
  digitalWrite(STEP_X, LOW);
  delayMicroseconds(Xdelay);
}

void Ystep(bool fwd)
{
  digitalWrite(DIR_Y, fwd);
  digitalWrite(STEP_Y, HIGH);
  digitalWrite(STEP_Y, LOW);
  delayMicroseconds(Ydelay);
}

void goto_step()
{
  bool fwd = true;
  int steps = getstep();
  if (steps < 0)
  {
    steps = - steps;
    fwd = false;
  }
  if (X)
    for (int i = 0; i < steps; i++)Xstep(fwd);
  else
    for (int i = 0; i < steps; i++)Ystep(fwd);
}

int getstep()
{
  Serial << "Enter number of steps:\n";
  return Serial.parseInt();
}

void stepto()
{
  int steps = 100;
  if (X)
    for (int i = 0; i < steps; i++)Xstep(FWD);
  else
    for (int i = 0; i < steps; i++)Ystep(FWD);
}

