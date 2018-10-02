#define DIR_X 2
#define STEP_X 3
#define DIR_Y 4
#define STEP_Y 5

#define CLAW_PWM 6
#define CLAW_Grasp 100
#define CLAW_Release 200

#define CLAW_MTR 10
#define CLAW_UP 11
#define CLAW_DOWN 12

#define nCLK_SS 9
#define nCOIL_SS 10

#define total_blocks 27

// change needed flags
boolean changeHourOne; // flag for when the currentHourOne needs to be replaced
boolean changeHourTwo;
boolean changeMinOne;
boolean changeMinTwo;

static int8_t lastSecond = -1;
static int8_t lastMinute = -1;
static int8_t lastHour = -1;

// stepper positions
int positionStepperX; // current position of the x stepper motor
int positionStepperY; // current position of the y stepper motor
int xDelay = 500;
int yDelay = 500;

typedef struct block
{
  int x;   // x location
  int y;  // y location
  int v;  // value of block
};

struct block idle_b[total_blocks - 4]; // declare places for idle blocks
struct block time_b[4];  //places for 4 blocks showing time
struct block empty;







