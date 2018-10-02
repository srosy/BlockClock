



block findBlock(int val) { // find a block, -1 == empty
  int i;
  for (i = 0; i < total_blocks; i++) {
    if (idle_b[i].v == val) {
      return idle_b[i];
      break;
    }
  }
}

void updateBlock(block oldBlock, block newBlock) {
  block temp = newBlock;
  newBlock = oldBlock;
  oldBlock = temp; // block information is switched
}

void isNowEmpty(block b) {
  // keeps the value of the block, just changes the location
  empty.x = b.x; // assign empty x
  empty.y = b.y; // assign empty y
}

void goToBlock(block b)
{
  bool fwd = true;
  int steps;
  //int steps = getstep();


  steps = getBlock_X(b); // get block b's x coordinate
  if (steps < 0)
  {
    steps = - steps;
    fwd = false;
  }
  for (int i = 0; i < steps; i++)Xstep(fwd);

  steps = getBlock_Y(b); // get block b's y coordinate
  if (steps < 0)
  {
    steps = - steps;
    fwd = false;
  }
  for (int i = 0; i < steps; i++)Ystep(fwd);
}

void initializeBlocks() {

  // initialize idle_b
  idle_b[0].x = 400;
  idle_b[0].y = 400;
  idle_b[0].v = 1;

  idle_b[1].x = 400;
  idle_b[1].y = 800;
  idle_b[1].v = 1; // fix vals

  idle_b[2].x = 400;
  idle_b[2].y = 800;
  idle_b[2].v = 1;

  idle_b[3].x = 400;
  idle_b[3].y = 800;
  idle_b[3].v = 1;

  idle_b[4].x = 400;
  idle_b[4].y = 800;
  idle_b[4].v = 2;

  idle_b[5].x = 400;
  idle_b[5].y = 800;
  idle_b[5].v = 2;

  idle_b[6].x = 400;
  idle_b[6].y = 800;
  idle_b[6].v = 2;

  idle_b[7].x = 400;
  idle_b[7].y = 800;
  idle_b[7].v = 3;

  idle_b[8].x = 400;
  idle_b[8].y = 800;
  idle_b[8].v = 3;

  idle_b[9].x = 400;
  idle_b[9].y = 800;
  idle_b[9].v = 3;

  idle_b[10].x = 400;
  idle_b[10].y = 800;
  idle_b[10].v = 4;

  idle_b[11].x = 400;
  idle_b[11].y = 800;
  idle_b[11].v = 4;

  idle_b[12].x = 400;
  idle_b[12].y = 800;
  idle_b[12].v = 4;

  idle_b[13].x = 400;
  idle_b[13].y = 800;
  idle_b[13].v = 5;

  idle_b[14].x = 400;
  idle_b[14].y = 800;
  idle_b[14].v = 5;

  idle_b[15].x = 400;
  idle_b[15].y = 800;
  idle_b[15].v = 5;

  idle_b[16].x = 400;
  idle_b[16].y = 800;
  idle_b[16].v = 6;

  idle_b[17].x = 400;
  idle_b[17].y = 800;
  idle_b[17].v = 6;

  idle_b[18].x = 400;
  idle_b[18].y = 800;
  idle_b[18].v = 7;

  idle_b[19].x = 400;
  idle_b[19].y = 800;
  idle_b[19].v = 7;

  idle_b[20].x = 400;
  idle_b[20].y = 800;
  idle_b[20].v = 8;

  idle_b[21].x = 400;
  idle_b[21].y = 800;
  idle_b[21].v = 8;

  idle_b[22].x = 400;
  idle_b[22].y = 800;
  idle_b[22].v = 9;

  idle_b[23].x = 400;
  idle_b[23].y = 800;
  idle_b[23].v = 9;

  // initialize time_b
  time_b[0].x = 4000;
  time_b[0].y = 400;
  time_b[0].v = 1; // represents hours to 10

  time_b[1].x = 4400;
  time_b[1].y = 400;
  time_b[1].v = 2; // hours to 2 (+10) so 12

  // initialize empty
  empty.x = 1200;  //initial empty coordinates
  empty.y = 1800;
  empty.v = -1;  // indicates empty
}
