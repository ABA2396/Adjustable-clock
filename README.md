# Adjustable-clock

实现功能
- 自动计时并由LED数码管显示当前时间。
- 按键更改当前调节的时间位置，提供左右移操作，修改时对应位置闪烁。
- 按键调节当前位置的时间，提供加减数值操作。
- 串口直接设置时间，传入格式为h时m分s秒*（例如设置时间为12时34分56秒，则传入h12m34s56*）支持同时修改任意位，会识别靠近传入字符串最靠后的匹配格式，最高支持当次传入20位字符串。

单片机
- 独立按键P3.0~P3.3
- 数码管段选P2.6
- 数码管位选P2.7
- 串口波特率4800
