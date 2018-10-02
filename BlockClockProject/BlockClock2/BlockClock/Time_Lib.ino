
void getTime()
{
  Serial << "Enter hour: ";
  H = Serial.parseInt();
  Serial << "\nEnter minute: \n\\";
  M = Serial.parseInt();
  printEnteredTime();
}

void printEnteredTime()
{
  Serial << H << ":" << M << "\n";
}

void chkTime()
{
  int T[4];
  T[0] = H / 10;
  T[1] = H % 10;
  T[2] = M / 10;
  T[3] = M % 10; // T has time by digit
  //printEnteredTime();
  if (verbose_) Serial << T[0] << T[1] << ":" << T[2] << T[3] << "\n";
  for (int i = 0; i <= 3; i++)
  {
    if (T[i] != time_b[i].v) updateTimeBlock(i, T[i]);
  }
}

void updateTimeBlock(int from, int T)
{
  int to = findval(-1);
  move2empty(from, to);  // move old number to empty spot

  to = from;  // now move to time
  from = findval(T);
  move2time(from, to);
}


int findval(int v)
{
  for (int i = 0; i < 24; i++)
  {
    if (idle_b[i].v == v)return i;
  }
  Serial << "block " << v << " not found\n";
  while(true);
}

void move2empty(int from, int to)
{
  moveBlockTime(from, to);  // move from time to empty spot in idle
  idle_b[to].v = time_b[from].v;
}

void move2time(int from, int to)
{
  moveBlockIdle(from, to);  // move from idle to time
  time_b[to].v = idle_b[from].v;
  idle_b[from].v = -1;  // moved so now this is the empty
  if(verbose_)Serial << "Empty block at: " << from << "\n";
}


void moveBlockIdle(int from, int to)
{
  if (verbose_) Serial << "Move Idle Block.  From: " << from << " to: " << to << "\n";
}
void moveBlockTime(int from, int to)
{
  if (verbose_) Serial << "Move Time Block.  From: " << from << " to: " << to << "\n";
}

