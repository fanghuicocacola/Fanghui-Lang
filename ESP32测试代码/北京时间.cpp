#include "SSD1306.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>

SSD1306  display(0x3c, 21, 22);

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 8 * 3600;
const int daylightOffset_sec = 0;

void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    display.println("Failed to obtain time");
    return;
  }
  String time = "BJT   "+String(timeinfo.tm_hour)+":"+String(timeinfo.tm_min);
  display.drawString(0, 0, "Time");
  display.display();
  display.clear();
  delay(1000);
  display.drawString(0, 0, time);
//   display.println(&timeinfo, "%F"); 
//   display.println(&timeinfo, "%T"); 
//   display.println(&timeinfo, "%A"); 
  display.display();
}

void setup() {
    Serial.begin(115200);
    WiFi.begin("forESP32","1357924680");
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    Serial.print("IP地址：");
    Serial.println(WiFi.localIP());
    display.init();
    display.drawString(0, 0, "Connected");
    display.display();
    /*  显示字母 */
    // display.setFont(ArialMT_Plain_16);       // 设置字体
    // display.drawString(0,0, "Temp:" +String("1")+"C"); // 将要显示的字母写入缓存
    // display.drawString(0,20, "Humidity:"+String("2")+"%"); // 将要显示的字母写入缓存
    // display.display();                       // 将缓存里的文字在屏幕上显示
    // delay(3000);		//3秒
    // display.clear(); 
    // display.display();         // 清除屏幕
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();

}



void loop() {
    delay(1000);
    //清除屏幕
    display.clear();
    //设置光标位置
    printLocalTime();
}