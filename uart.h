#ifndef _UART_H_
#define _UART_H_

#include <reg51.h>
#include <string.h>
#include <stdlib.h>
#include "key.h"

static unsigned char k = 0;      // 串口数据位数
static unsigned char ch[20] = 0; // 接收串口数据

void serial_port();                      // 串口中断函数
void settime();                          // 设置时间

#endif