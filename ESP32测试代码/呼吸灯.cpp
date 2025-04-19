/*
 * ESP32使用PWM实现呼吸灯程序
 */
#include <cstring>
#include <string>
 
/* 设置led输出引脚号 */
uint8_t led_pin = 2;
uint8_t led_ch = 1;

void setup() 
{            
  Serial.begin(115200);
  delay(10); 

  /* 1. 使用ledc通道1，设置频率为1kHz，分辨率为10位 */
  double f = ledcSetup(led_ch, 1000, 10);  
  Serial.print("F=");Serial.println(f); /* 打印实际设置的频率*/

  /* 2. 将LED引脚绑定到ledc通道1 */
  ledcAttachPin(led_pin, led_ch);

  /* 3. 设置ledc通道占空比为512/1024=50% */
  ledcWrite(led_ch, 511);
}

void loop() 
{
  uint8_t dir = 0;
  uint32_t pwmval = 255;
  while(1)
  {
    if(dir) pwmval++;                 // dir==1  pwmval递增
    else pwmval--;                    // dir==0  pwmval递减
    if( pwmval == 0 ) dir=1;          // pwmval降低至0后，方向为递增
    if( pwmval >= 500) dir=0;         // pwmval递增到500后，方向改为递减
    ledcWrite(led_ch, pwmval);           // 修改占空比
    if( pwmval==0 ) delay(500);    // 在LED熄灭时等待300ms
    delay(5);
  }
}
