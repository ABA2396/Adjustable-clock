#include "display.h"

sbit dula = P2 ^ 6;
sbit wela = P2 ^ 7;
unsigned char code wei[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f, 0xff};                    // 八段位码
unsigned char code duan[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x40, 0x00}; //  段码'0'~'9' '-' 'null'

unsigned char show[8] = {0};
int timer = 0, hour = 10, min = 0, sec = 0; // 时间变量

void display(unsigned char d, unsigned char w) // 显示函数
{
    P0 = 0xff; // 消隐
    wela = 1;
    wela = 0;
    P0 = duan[d]; // 段
    dula = 1;
    dula = 0;
    P0 = wei[w]; // 位
    wela = 1;
    wela = 0;
}

void reset_show() // 设置显示数值
{
    int i = timer - ((timer >> 3) << 3);
    shine_flag = timer < 500 && timer >= 0 ? 0 : 1; // 判断是否需要闪烁
    switch (i)
    {
    case 0:
        show[i] = (shine_flag && (key_position == 1)) ? 11 : hour / 10; // 显示时钟第一位 判断是否需要闪烁
        break;
    case 1:
        show[i] = (shine_flag && (key_position == 1)) ? 11 : hour % 10; // 显示时钟第二位
        break;
    case 2:
        show[i] = 10; // 显示分隔符 -
        break;
    case 3:
        show[i] = (shine_flag && (key_position == 2)) ? 11 : min / 10; // 显示时钟第三位
        break;
    case 4:
        show[i] = (shine_flag && (key_position == 2)) ? 11 : min % 10; // 显示时钟第四位
        break;
    case 5:
        show[i] = 10; // 显示分隔符 -
        break;
    case 6:
        show[i] = (shine_flag && (key_position == 3)) ? 11 : sec / 10; // 显示时钟第五位
        break;
    case 7:
        show[i] = (shine_flag && (key_position == 3)) ? 11 : sec % 10; // 显示时钟第六位
        break;
    }
}
