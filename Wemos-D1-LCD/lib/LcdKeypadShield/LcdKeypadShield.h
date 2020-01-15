#include <Wire.h>
#include <LiquidCrystal.h>
#include "Button.h"
#include "BoardType.h"

class LcdKeypadShield : public LiquidCrystal
{
private:
    /*Default resistor deviation*/
    const static int _defaultResistorCurrentDeviation = 25;

    /*Buttons analog pin*/
    int _analogBtnPin;

    /*The number of buttons on the shield*/
    const static int _buttonsCount = 5;

    /*Analog max value (no key pressed)*/
    const static int _noKeyAnalogValue = 1024;

    /*This variable takes into account the possible 
    unstable current value when reading the analog button*/
    int _resistorCurrentDeviation;
    
    //Buttons analog values
    int _buttonsValues[_buttonsCount]{_noKeyAnalogValue};

    /*Check if the value is within the deviation with the resistor*/
    bool isInRange(const int &analogValue,const int &etalonValue);

    /*Get average analog value for user set*/
    int getAverageBtnValue();
    
public:
    //Arbitrary connection of pins to LCD
    LcdKeypadShield(const uint8_t &rs,const uint8_t &enable, 
                    const uint8_t &d4,const  uint8_t &d5,const uint8_t &d6,const uint8_t &d7,
                    const int &aBtnPin);

    ~LcdKeypadShield();

    /*This method can be used if the shield display is connected directly to the board. 
    The detode will automatically initialize the display for your board*/
    static LcdKeypadShield createByBoaard(const BoardType &board);

    /*Button press check*/
    bool isAvailableButton();

    /*Returns the pressed button*/
    Button getButton();

    /*Manual setting of analog button value*/
    void setButtonAnalogValue(const Button &button,const int &analogButtonValue);

    /*Returns the deviation of the resistor values ​​when the button contacts fluctuate*/
    //int getResistorDeviation();

    /*Set the deviation of the resistor values ​​when the button contacts fluctuate*/
    //void setResistorDeviation(const int &resistorDeviation);
    
    /*Automatically adjust button values using the user menu.
    The method helps a lot if you need to constantly change the shield or if you need quick setup*/
    void userButtonsAutoCorrect();
};