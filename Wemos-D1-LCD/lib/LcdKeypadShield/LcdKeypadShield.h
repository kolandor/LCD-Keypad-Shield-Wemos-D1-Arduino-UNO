#include <LiquidCrystal.h>
#include "BoardType.h"
#include "Button.h"

class LcdKeypadShield : public LiquidCrystal
{
private:

    /*The number of buttons on the shield*/
    const static int _buttonsCount = 5;

    /*This variable takes into account the possible 
    unstable current value when reading the analog button*/
    const int _resistorCurrentDeviation = 25;
    
    //Buttons analog values
    int _buttonsValues[_buttonsCount]{0};

public:
    //Arbitrary connection of pins to LCD
    LcdKeypadShield(const uint8_t &rs,const uint8_t &enable, 
                    const uint8_t &d4,const  uint8_t &d5,const uint8_t &d6,const uint8_t &d7);

    ~LcdKeypadShield();

    /*This method can be used if the shield display is connected directly to the board. 
    The detode will automatically initialize the display for your board*/
    static LcdKeypadShield createByBoaard(const BoardType &board);

    bool isAvailableButton();

    Button getButton();

    void setButtonValue(Button button, int analogButtonValue);

    void userButtonsAutoCorrect();
};