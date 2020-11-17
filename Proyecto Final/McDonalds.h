typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define FACTOR 1
#define RESTAURANT 1
#define DRIVE_THRU 2

void Restaurant();
void Drive_Thru();
void delay(uint8 number_of_seconds);
uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count);