#include <Arduino.h>
#include <SPI.h>
#include <BluetoothSerial.h>
#include <set>
//A轮 D16,D17
//B轮 D19,D21
//C轮 D2,D15
//D轮 D22,D23
#define A_Pin1 GPIO_NUM_16
#define A_Pin2 GPIO_NUM_17
#define B_Pin1 GPIO_NUM_19
#define B_Pin2 GPIO_NUM_21
#define C_Pin1 GPIO_NUM_2
#define C_Pin2 GPIO_NUM_15
#define D_Pin1 GPIO_NUM_22
#define D_Pin2 GPIO_NUM_23
BluetoothSerial SerialBT;

void init_bluetooth()
{
    Serial.begin(115200);
    SerialBT.begin("Car_Controller"); // Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");
}
const std::set<int> pin_set = {
    A_Pin1, A_Pin2, B_Pin1, B_Pin2, C_Pin1, C_Pin2, D_Pin1, D_Pin2};
void setup(void)
{
    init_bluetooth();

    for (auto pin : pin_set)
        pinMode(pin, OUTPUT);
}

// 1 正转, 0 反转
void set_A(int state)
{
    digitalWrite(A_Pin1, state);
    digitalWrite(A_Pin2, state ^ 1);
}
void set_B(int state)
{
    digitalWrite(B_Pin1, state);
    digitalWrite(B_Pin2, state ^ 1);
}
void set_C(int state)
{
    digitalWrite(C_Pin1, state);
    digitalWrite(C_Pin2, state ^ 1);
}
void set_D(int state)
{
    digitalWrite(D_Pin1, state);
    digitalWrite(D_Pin2, state ^ 1);
}
void forward()
{
    set_A(1);
    set_B(1);
    set_C(1);
    set_D(1);
}
void back()
{
    set_A(0);
    set_B(0);
    set_C(0);
    set_D(0);
}
void stop()
{
    for (auto pin : pin_set)
    {
        digitalWrite(pin, 0);
    }
}
String ble_read()
{
    return SerialBT.readString();
}
void loop()
{
    if (SerialBT.available())
    {
        String s = ble_read();
        Serial.write(s.c_str());
        s.trim();
        if (s == "forward")
            forward();
        else if (s == "back")
            back();
        else if (s == "stop")
            stop();
    }
    delay(5);
}
