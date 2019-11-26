#include <HXstomp.h>

HXstomp hxstomp;

void setup()
{
  Serial.begin(31250);
  hxstomp.setSerial(&Serial);

  hxstomp.presetSet(0);
  hxstomp.snapshot1();
}

void loop()
{

  hxstomp.modePreset();
  delay(500);
  hxstomp.presetNext();
  delay(1000);
  hxstomp.modeSnapshot();
  delay(500);
  hxstomp.snapshot1();
  delay(500);
  hxstomp.snapshot2();
  delay(500);
  hxstomp.snapshot3();
  delay(500);
  hxstomp.tuner();
  delay(2000);
  hxstomp.tuner();
  delay(1000);
  hxstomp.modeStomp();
  delay(200);
  hxstomp.fs1();
  delay(500);
  hxstomp.fs1();
  delay(500);
  hxstomp.fs2();
  delay(500);
  hxstomp.fs2();
  delay(500);
  hxstomp.fs3();
  delay(500);
  hxstomp.fs3();
  delay(500);
}
