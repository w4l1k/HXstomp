#include <HXstomp.h>

HXstomp hxstomp(10);

void setup()
{
  Serial.begin(31250);
  hxstomp.setSerial(&Serial);
}

void loop()
{

  for (int i = 1; i <= 100; i++ )
  {
    hxstomp.tapTempo();
    delay(250 + i * 10);
  }
}