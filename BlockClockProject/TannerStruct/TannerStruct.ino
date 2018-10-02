
struct block
{
  int x;   // x location
  int y;  // y location
  int v;  // value of block
};

then an array of these structures

#define total_blocks 27;

struct block idle_b[total_blocks-4];  // declare places for idle blocks
struct block time_b[4];  //places for 4 blocks showing time
struct block empty;

// initialize idle_b
idle_b.[0]x = 400;
idle_b[0].y = 400;
idle_b[0].v = 1;

idle_b.[1]x = 400;
idle_b[1].y = 800;
idle_b[1].v = 1;
// and 21 more

// initialize time_b
time_b[0].x = 4000;
time_b[0].y = 400;
time_b[0].v = 1; // hours to 10

time_b[1].x = 4400;
time_b[1].y = 400; 
time_b[1].v = 2: // hours to 2 (+10) so 12

// minutes


// initialize empty
empty.x = 1200;  //initial empty coordinates
empty.y = 1800;
empty.v = -1;  // indicates empty

// then each time you change the time, you move the changed digit to the empty spot.  Then search the idle array for the digit you need.  Pick up that digit.  Its former location is now empty.  Put that digit in the proper time slot.
// keep going until the time is correct.
