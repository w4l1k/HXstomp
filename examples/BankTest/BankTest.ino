#include <HXstomp.h>

HXstomp hxstomp;

void setup()
{
    Serial.begin(31250);
    hxstomp.setSerial(&Serial);

    hxstomp.presetSet(0);
}

void loop()
{

    for (byte i = 1; i <= 42; i++)
    {
        for (byte j = 1; j <= 3; j++)
        {
            hxstomp.bankSet(i, j);
            delay(500);
        }
    }
}