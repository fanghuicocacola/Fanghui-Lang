// #include <OneWire.h> //可以不引入，因为DallasTemperature.h中已经引入了OneWire.h
#include <DallasTemperature.h>
#include <U8g2lib.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

HTTPClient http;

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* reset=*/ U8X8_PIN_NONE);   // ESP32 Thing, pure SW emulated I2C

#define ONE_WIRE_BUS 4
//1-wire数据总线连接在IO4
OneWire oneWire(ONE_WIRE_BUS);       //声明
DallasTemperature sensors(&oneWire); //声明

unsigned long previousMillis = 0; //毫秒时间记录
const long interval = 1000;       //时间间隔
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 28800;
const int daylightOffset_sec = 0;
DynamicJsonDocument doc(1024);
DynamicJsonDocument doc1(1024);

void Print_init(){
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312);
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  // u8g2.setCursor(0, 15);
  // u8g2.print("Hello World!");
  // u8g2.setCursor(0, 40);
  // u8g2.print("你好ESP32");
  // u8g2.sendBuffer();
  // delay(1000);
}

void printLocalTime(){
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    u8g2.clearBuffer();
    u8g2.setCursor(0, 30);
    u8g2.println("Failed to obtain time");
    u8g2.sendBuffer();
    return;
  }
  String time = "北京时间"+String(timeinfo.tm_hour)+":"+String(timeinfo.tm_min);
  u8g2.clearBuffer();
  delay(1000);
  u8g2.setCursor(0, 50);
  u8g2.print(time);
  u8g2.sendBuffer();
}

void printLocalWeather(){
    http.begin("http://www.weather.com.cn/data/cityinfo/101191201.html");
    int httpCode = http.GET();
    if(httpCode == HTTP_CODE_OK){
      String pageData = http .getString();
      //Serial.println(pageData);
      deserializeJson(doc,pageData);
      JsonObject obj = doc.as<JsonObject>();
      String weatherInfo = obj["weatherinfo"];
      deserializeJson(doc1,weatherInfo);
      JsonObject obj1 = doc1.as<JsonObject>();
      String city = obj1["city"];
      String temp1 = obj1["temp1"];
      String temp2 = obj1["temp2"];
      String weather = obj1["weather"];
      String cityInfo ="地点"+ city;
      String tempInfo ="温度:" + temp1 + "--" + temp2;
      String cityWeatherinfo = "天气:" + weather;
      Serial.println("获得天气情况如下：");
      Serial.print(cityInfo);
      Serial.print(tempInfo);
      Serial.println(cityWeatherinfo);
      u8g2.clearBuffer();
      u8g2.setCursor(0, 16);
      u8g2.print("今日天气:");
      u8g2.setCursor(0, 32);
      u8g2.print(cityInfo);
      u8g2.setCursor(0, 48);
      u8g2.print(tempInfo);
      u8g2.setCursor(0,60);
      u8g2.print(cityWeatherinfo);
      u8g2.sendBuffer();
      delay(1000);
    }else{
      Serial.println("GET ERR");
    }
    http.end();
}
void PrintRoomTemperature(){
  //以下段落相当于每秒读取前次温度，并发起新一次温度转换
  unsigned long currentMillis = millis();         //读取当前时间
  if (currentMillis - previousMillis >= interval) //如果和前次时间大于等于时间间隔
  {
    previousMillis = currentMillis; //更新时间记录

    float tempC = sensors.getTempCByIndex(0); //获取索引号0的传感器摄氏温度数据
    if (tempC != DEVICE_DISCONNECTED_C)       //如果获取到的温度正常
    {
      Serial.print("\n室内温度是： ");
      Serial.print(tempC);
      Serial.println(" ℃");
      u8g2.clearBuffer();
      u8g2.setCursor(0, 50);
      u8g2.print("室温"+String(tempC)+"度");
      u8g2.sendBuffer();
    }
    sensors.requestTemperatures(); //发起新的温度转换
  }
}

void WiFi_Connected(){
  WiFi.begin("forESP32","1357924680");
  while(WiFi.status() != WL_CONNECTED){
      delay(500);
  }
  Serial.print("IP地址：");
  Serial.println(WiFi.localIP());
  u8g2.clearBuffer();
  u8g2.setCursor(0, 50);
  u8g2.print("WiFi Connected");
  u8g2.sendBuffer();
  delay(2000);
}

void setup(void)
{
  Serial.begin(115200);
  Print_init();
  int y=1;//调节位移速度，可用于加快字符位移速度
  for(int x=0;x<20;x+=y)
  {
    u8g2.clearBuffer();         
    u8g2.drawStr(x,10,"The device is booting"); 
    u8g2.drawStr(x-128,10,"The device is booting");
    delay(6);//延时程序，可以降低位移速度
    u8g2.sendBuffer();
  }
  WiFi_Connected();
  sensors.begin(); //初始化总线
  sensors.setWaitForConversion(false); //设置为非阻塞模式
}

void loop(void)
{
  Print_init();
  PrintRoomTemperature();
  delay(2000);
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  if(WiFi.status() == WL_CONNECTED){
    delay(2000);
    printLocalWeather();
    delay(2000);
  }
  else
  {
    Serial.println("WiFi  Disconnect");
  }

}
