/* Experiment No: 05
   Interface a stepper motor to control it in clockwise and anti-clockwise directions
*/

#include <lpc21xx.h>

void clockwise(void);
void anti_clockwise(void);

unsigned long int var1, var2;
unsigned int i = 0, j = 0, k = 0;

int main(void)
{
    /* Configure P0.12 to P0.15 as GPIO output */
    PINSEL0 = 0x00FFFFFF;
    IO0DIR |= 0x0000F000;

    while(1)
    {
        /* Rotate clockwise 50 times */
        for (j = 0; j < 50; j++)
            clockwise();

        /* Delay to show anti-clockwise rotation */
        for (k = 0; k < 65000; k++);

        /* Rotate anti-clockwise 50 times */
        for (j = 0; j < 50; j++)
            anti_clockwise();

        /* Delay to show clockwise rotation */
        for (k = 0; k < 65000; k++);
    }
}

/* Clockwise rotation function using ABCD stepping */
void clockwise(void)
{
    var1 = 0x00000800;          /* Initial value for clockwise */
    for (i = 0; i <= 3; i++)   /* ABCD stepping sequence */
    {
        var1 = var1 << 1;       /* Shift left for clockwise */
        var2 = ~var1;
        var2 = var2 & 0x0000F000;
        IO0PIN = ~var2;

        for (k = 0; k < 3000; k++);    /* Step speed variation delay */
    }
}

/* Anti-clockwise rotation function using ABCD stepping */
void anti_clockwise(void)
{
    var1 = 0x00010000;          /* Initial value for anti-clockwise */
    for (i = 0; i <= 3; i++)   /* ABCD stepping sequence */
    {
        var1 = var1 >> 1;       /* Shift right for anti-clockwise */
        var2 = ~var1;
        var2 = var2 & 0x0000F000;
        IO0PIN = ~var2;

        for (k = 0; k < 3000; k++);    /* Step speed variation delay */
    }
}
