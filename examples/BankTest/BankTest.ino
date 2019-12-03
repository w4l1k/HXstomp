#include <HXstomp.h>

HXstomp hxstomp(10); //MIDI CANAL 10

void setup()
{
    Serial.begin(31250);
    hxstomp.setSerial(&Serial);

    hxstomp.bankSet(1, hxstomp.A);
    delay(1000);
    hxstomp.bankSet(1, hxstomp.B);
    delay(1000);
    hxstomp.bankSet(1, hxstomp.C);
    delay(1000);

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