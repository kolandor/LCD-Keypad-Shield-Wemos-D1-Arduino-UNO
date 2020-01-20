# Wemos D1 / Arduino UNO LED display

A library that simplifies connecting and configuring the LCD Keypad Shield to Wemos D1 and Arduino UNO.

Functional:
- Smart LCD Keypad Shield Customization
- Simplified LCD Keypad Shield setup system connected directly to the board
- Autodetection mechanisms of pressed buttons
- Setting Button Values
- Management of deviations of analog values of buttons

In this example, I will show how using [this](https://github.com/kolandor/Wemos-D1-as-Arduino-UNO-pins) you can connect the Arduino Display Shield to Wemos D1

**Quick start Wemos D1 R1**
```cpp
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
  //CODE
}
```

**Quick start UNO**
```cpp
//Create oobject by board type
LcdKeypadShield lcd = LcdKeypadShield::createByBoaard(UNO);

void setup() 
{
  //set lcd size
  lcd.begin(16,2);
  //Auto set buttons values
  lcd.userButtonsAutoCorrect();
}

void loop()
{
  //CODE
}
```
