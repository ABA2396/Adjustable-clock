#include "uart.h"

void serial_port() interrupt 4 // 串口中断函数
{
    unsigned char temp = 0;
    if (RI == 1)
    {
        temp = SBUF;
        if (temp != '*')
        {
            ch[k++] = temp;
        }
        else
        {
            ch[k] = '\0';
            settime(); // 设置时间
            k = 0;     // 重置接收串口数据位数
            key_position = 0;
        }
    }
    RI = 0;
}

void settime() // 设置时间
{
    int i;
    for (i = 0; i < strlen(ch); ++i) // 将接收到的数据转化为数字
    {
        switch (ch[i])
        {
        case 'h':
            hour = atoi(ch + (++i));
            break;
        case 'm':
            min = atoi(ch + (++i));
            break;
        case 's':
            sec = atoi(ch + (++i));
        default:
            break;
        }
    }
}
