#include "key.h"

char key_position = 0;

unsigned char key_flag()
{
    if (key1 && key2 && key3 && key4) // 松手复位
        k_flag = 0;
    if (!(key1 && key2 && key3 && key4)) // 按下判断
    {
        delay(1);                            // 消抖
        if (!(key1 && key2 && key3 && key4)) // 再次按下判断
            if (k_flag == 0)
            {
                k_flag = 1; // 置位
                if (!key1)
                    return 1; // 返回按下的按键编号
                if (!key2)
                    return 2;
                if (!key3)
                    return 3;
                if (!key4)
                    return 4;
            }
    }
    return 0;
}

void key_down() // 按下按键时更改时间
{
    switch (key_flag()) // 判断按下的按键
    {
    case 0:
        break;
    case 1:                     // 按下<<
        if (--key_position < 0) // 判断是否越界
            key_position = 3;
        break;
    case 2:                     // 按下>>
        if (++key_position > 3) // 判断是否越界
            key_position = 0;
        break;
    case 3: // 按下++
        if (key_position == 1)
        {
            if (++hour >= 24)
                hour = 0;
        }
        if (key_position == 2)
        {
            if (++min >= 60)
                min = 0;
        }
        if (key_position == 3)
        {
            if (++sec >= 60)
                sec = 0;
        }
        break;
    case 4: // 按下--
        if (key_position == 1)
        {
            if (--hour <= -1)
                hour = 23;
        }
        if (key_position == 2)
        {
            if (--min <= -1)
                min = 59;
        }
        if (key_position == 3)
        {
            if (--sec <= -1)
                sec = 59;
        }
        break;
    default:
        break;
    }
}
