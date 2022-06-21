#ifndef _DISPLAY_H_
#define _DISPLAY_H

#include <reg51.h>
#include "key.h"

extern unsigned char show[];
extern int timer, hour, min, sec;
static unsigned char shine_flag;

void display(unsigned char d, unsigned char w);
void reset_show();

#endif