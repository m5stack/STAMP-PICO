/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with STAMP-PICO sample source code
*                          配套  STAMP-PICO 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/stamp_pico
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/stamp_pico
*
* describe: Digital to analog.
* date：2021/9/24
*******************************************************************************
*/
#include <Arduino.h>
#include <analogWrite.h>

/* After STAMP-PICO is started or reset
  the program in the setUp () function will be run, and this part will only be run once.
  在 STAMP-PICO 启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup() {
  Serial.begin(115200);
  pinMode(25,OUTPUT);
  analogWriteResolution(25); // set resolution to 10 bits for the pins.  将引脚的分辨率设置为 10 位
}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
在setup()函数中的程序执行完后，会接着执行loop()函数中的程序
loop()函数是一个死循环，其中的程序会不断的重复运行 */
void loop() {
  for(int i = 0; i<255;i++){
    analogWrite(25,i);
    Serial.printf("analogWrite:%d\n",i);
    delay(20);
  }
  for(int i = 255; i>0;i--){
    analogWrite(25,i);
    Serial.printf("analogWrite:%d\n",i);
    delay(20);
  }
}
