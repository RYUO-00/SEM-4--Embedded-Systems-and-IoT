/* Experiment No: 06
   Interface and control a DC Motor in clockwise and anti-clockwise direction
*/

#include <lpc214x.h>

void clockwise(void);
void anti_clockwise(void);

unsigned int j = 0;

int main()
{
    /* Set P0.7 and P0.8 as output for motor control */
    IO0DIR = 0x00000900;
    IO0SET = 0x00000100;

    while(1)
    {
        clockwise();
        for (j = 0; j < 400000; j++);  /* Delay */

        anti_clockwise();
        for (j = 0; j < 400000; j++);  /* Delay */
    }
}

/* Rotate motor clockwise */
void clockwise(void)
{
    /* Stop motor and turn off relay */
    IO0CLR = 0x00000900;

    /* Small delay to allow motor to turn off */
    for (j = 0; j < 10000; j++);

    /* Select P0.8 line for clockwise and turn on motor */
    IO0SET = 0x00000900;
}

/* Rotate motor anti-clockwise */
void anti_clockwise(void)
{
    /* Stop motor and turn off relay */
    IO0CLR = 0x00000900;

    /* Small delay to allow motor to turn off */
    for (j = 0; j < 10000; j++);

    /* Select P0.8 line for anti-clockwise */
    IO0SET = 0x00000100;
}
