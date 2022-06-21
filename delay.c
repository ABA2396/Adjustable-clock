#include "delay.h"

void delay(unsigned int ms)
{
    char i;
    while (ms--)
        for (i = 0; i < 123; ++i)
            ;
}
