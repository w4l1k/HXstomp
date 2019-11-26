#include <HXstomp.h>

HXstomp hxstomp;

void setup()
{
    Serial.begin(31250);
    hxstomp.setSerial(&Serial);
}

void loop()
{
    for (int i = 0; i <= 100; i++)
    {
        hxstomp.exp1(i);
        hxstomp.exp2(i);
        delay(500);
    }
    for (int i = 100; i >= 0; i--)
    {
        hxstomp.exp1(i);
        hxstomp.exp2(i);
        delay(500);
    }
}