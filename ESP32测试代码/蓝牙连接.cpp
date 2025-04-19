#include <BluetoothSerial.h>
#include <cstring>
#include <string>

BluetoothSerial SerialBT;

void setup()
{
    Serial.begin(9600);
    SerialBT.begin("HttoESP"); // Bluetooth device name
    SerialBT.setPin("1234");
    Serial.println("The device started, now you can pair it with bluetooth!");
}
uint8_t buf[512];
void loop()
{
    if (SerialBT.available())
    {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        // 读取手机发送的信息
        SerialBT.readBytes(buf, 1024);
        // 输出到控制台
        Serial.write(buf);

        // 通过蓝牙发送hello world
        const char *msg = "终于连上了，哭了";
        SerialBT.write((uint8_t *)msg, strlen(msg));
    }
    delay(20);
}
