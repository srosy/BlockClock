// 00011122334455566778899 empty = 24
// 1234 in time = 4
// 28 blocks total
#define xinit 8000
#define xwidth 500
#define yinit 3000
#define ywidth 600
#define T_xinit 8500
#define T_xwidth 750
#define T_yinit 1500

void initializeBlocks()
{
  int v[24] = {0, 1, 2, 3, -1, 4, 0, 1, 2 ,5 ,6 ,7 ,0 , 1, 3, 8, 9, 5, 4, 5, 6, 7, 8, 9}; // initial values
//  int v[24] = {0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, -1}; // initial values

  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 6; x++)
    {
      int i = (y * 6) + x;
      idle_b[i].x = xinit + x * xwidth;
      idle_b[i].y = yinit + y * ywidth;
      if(verbose_)Serial << "i: " << i << " inserting: " << v[i] << "\n";
      idle_b[i].v = v[i];
    }

  // initialize time_b  // with 12:34
  for (int i = 0; i < 4; i++)
  {
    time_b[i].x = T_xinit + i * T_xwidth;
    time_b[i].y = T_yinit;
    time_b[i].v = i + 1;
  }
}

void printIdleBlocks()
{
  Serial << "Idle ----------------------------------\n";
  for (int i = 0; i < 24; i++)
  {
    Serial << i << ": ";
    printBlock(idle_b[i]);
  }
}

void printTimeBlocks()
{
  Serial <<  "Time ----------------------------------\n";
  for (int i = 0; i < 4; i++)
  {
    Serial << i << ": ";
    printBlock(time_b[i]);
  }
}

void printBlock(block b)
{
  Serial << "(" << b.x << "," << b.y << ")  "  << b.v << "\n";
}

void checkBlockCounts()
{
  int blockerr = checkBlocks();
  if (blockerr != -2)
  {
    Serial << "Block error.  Wrong number of " << blockerr << " blocks." ;
    printTimeBlocks();
    printIdleBlocks();
    while (true);
  }
}

int checkBlocks()
{
  if (countBlock(0) != 3)return 0;
  if (countBlock(1) != 4)return 1;
  if (countBlock(2) != 3)return 2;
  if (countBlock(3) != 3)return 3;
  if (countBlock(4) != 3)return 4;
  if (countBlock(5) != 3)return 5;
  if (countBlock(6) != 2)return 6;
  if (countBlock(7) != 2)return 7;
  if (countBlock(8) != 2)return 8;
  if (countBlock(9) != 2)return 9;
  if (countBlock(-1) != 1)return -1;
  return -2;
}

int countBlock(int v)
{
  int count = 0;
  for (int i = 0; i < 4; i++) if (time_b[i].v == v) count++;
  for (int i = 0; i < 24; i++) if (idle_b[i].v == v) count++;
  if (verbose_) Serial << "v: " << v << " count: " << count << "\n";
  return count;
}

