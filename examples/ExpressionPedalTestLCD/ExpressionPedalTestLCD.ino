#include <HXstomp.h>
#include <LiquidCrystal_I2C.h>

HXstomp hxstomp(10); //MIDI CANAL 10
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup()
{
    Serial.begin(31250);
    hxstomp.setSerial(&Serial);

    lcd.init();
    lcd.backlight();
}

void loop()
{
 
  for (int i = 0; i <= 100; i++)
    {
      hxstomp.exp1(i, true);
      hxstomp.exp2(i, true);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.print(i);
      delay(500);
    }
    for (int i = 100; i >= 0; i--)
    {
      hxstomp.exp1(i);
      hxstomp.exp2(i);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.print(i);
      delay(500);
    }  
    delay(1000);
}