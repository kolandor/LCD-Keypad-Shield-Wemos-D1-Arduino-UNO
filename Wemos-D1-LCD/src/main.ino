#include "WemosD1R1Pins.h"
#include "LcdKeypadShield.h"

void whichButtonIsPressed();

//Create oobject by board type
LcdKeypadShield lcd = LcdKeypadShield::createByBoaard(WemosD1R1);

void setup() 
{
  //set lcd size
  lcd.begin(16,2);
  //Auto set buttons values
  lcd.userButtonsAutoCorrect();
}

void loop()
{
  whichButtonIsPressed();
  delay(100);
}

void whichButtonIsPressed()
{
  lcd.clear();

  switch (lcd.getButton())
  {
  case Select:
    lcd.print("Select");
    break;

  case Left:
    lcd.print("Left");
    break;

  case Right:
    lcd.print("Right");
    break;

  case Up:
    lcd.print("Up");
    break;

  case Down:
    lcd.print("Down");
    break;

  default:
    lcd.print("None");
    break;
  }
}