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

template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}

int second = 12;
int minute = 30;
int hour = 0;

int day = 3; // Sunday=1, Monday=2, ..., Saturday=7.
int date = 27; 
int month = 03;
int year = 18;
