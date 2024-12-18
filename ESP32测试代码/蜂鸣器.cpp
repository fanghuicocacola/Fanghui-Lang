#include<HardwareSerial.h>
#define LEDC_CHANNEL_0 0
// use 13 bit precission for LEDC timer
#define LEDC_TIMER_13_BIT 13
// 定义工具IO口
#define LED_PIN 16
// 创建音乐旋律列表，超级玛丽
int melody[] = {330, 330, 330, 262, 330, 392, 196, 262, 196, 165, 220, 247, 233, 220, 196, 330, 392, 440, 349, 392, 330, 262, 294, 247, 262, 196, 165, 220, 247, 233, 220, 196, 330, 392, 440, 349, 392, 330, 262, 294, 247, 392, 370, 330, 311, 330, 208, 220, 262, 220, 262,
                294, 392, 370, 330, 311, 330, 523, 523, 523, 392, 370, 330, 311, 330, 208, 220, 262, 220, 262, 294, 311, 294, 262, 262, 262, 262, 262, 294, 330, 262, 220, 196, 262, 262, 262, 262, 294, 330, 262, 262, 262, 262, 294, 330, 262, 220, 196};
// 创建音调持续时间列表
int noteDurations[] = {8, 4, 4, 8, 4, 2, 2, 3, 3, 3, 4, 4, 8, 4, 8, 8, 8, 4, 8, 4, 3, 8, 8, 3, 3, 3, 3, 4, 4, 8, 4, 8, 8, 8, 4, 8, 4, 3, 8, 8, 2, 8, 8, 8, 4, 4, 8, 8, 4, 8, 8, 3, 8, 8, 8, 4, 4, 4, 8, 2, 8, 8, 8, 4, 4, 8, 8, 4, 8, 8, 3, 3, 3, 1, 8, 4, 4, 8, 4, 8, 4, 8, 2, 8, 4, 4, 8, 4, 1, 8, 4, 4, 8, 4, 8, 4, 8, 2};
void setup()
{
}
void loop()
{
  int noteDuration;
  for (int i = 0; i < sizeof(noteDurations); ++i)
  {
    noteDuration = 800 / noteDurations[i];
    ledcSetup(LEDC_CHANNEL_0, melody[i] * 2, LEDC_TIMER_13_BIT);
    ledcAttachPin(LED_PIN, LEDC_CHANNEL_0);
    ledcWrite(LEDC_CHANNEL_0, 50);
    delay(noteDuration * 1.30);
  }
}
