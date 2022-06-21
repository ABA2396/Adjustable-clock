#ifndef _KEY_H_
#define _KEY_H_

#include <reg51.h>
#include "delay.h"
#include "timer.h"

sbit key1 = P3 ^ 0; // 独立按键
sbit key2 = P3 ^ 1;
sbit key3 = P3 ^ 2;
sbit key4 = P3 ^ 3;

extern char key_position;        // 按键位置
static unsigned char k_flag = 0; // 按键标志位

unsigned char key_flag();
void key_down();

#endif