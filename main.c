#include "main.h"

void main()
{
    init();   // 初始化工作
    while (1) // 主循环
    {
        key_down();    // 判断按键是否按下
        reset_show();  // 重新设置显示数值
    }
}
