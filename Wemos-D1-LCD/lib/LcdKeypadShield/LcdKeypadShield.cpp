#include "LcdKeypadShield.h"
#include "WemosD1R1Pins.h"

//////////////////////////////////////PUBLIC METHODS//////////////////////////////////////

LcdKeypadShield::LcdKeypadShield(const uint8_t &rs,const  uint8_t &enable, 
                                const uint8_t &d4,const  uint8_t &d5,const  uint8_t &d6,const  uint8_t &d7, const int &aBtnPin) : 
                                LiquidCrystal(rs, enable, d4, d5, d6, d7)
{
    this->_analogBtnPin = aBtnPin;
    this->_resistorCurrentDeviation = this->_defaultResistorCurrentDeviation;
}

LcdKeypadShield::~LcdKeypadShield()
{
}

LcdKeypadShield LcdKeypadShield::createByBoaard(const BoardType &board)
{
    switch (board)
    {
    case UNO:
        return LcdKeypadShield(8, 9, 4, 5, 6, 7, 0);
        break;

    case WemosD1R1:
        return LcdKeypadShield(D8, D9, D4, D5, D6, D7, A0);
        break;
    }

    return LcdKeypadShield(0, 0, 0, 0, 0, 0, 0);
}


bool LcdKeypadShield::isAvailableButton()
{
    return !isInRarnge(analogRead(this->_analogBtnPin), this->_noKeyAnalogValue);
}

Button LcdKeypadShield::getButton()
{
    int analogValue = analogRead(this->_analogBtnPin);

    if (isAvailableButton())
    {
        for (size_t i = 0; i < this->_buttonsCount; i++)
        {
            if (/* condition */)
            {
                /* code */
            }
        }
    }
    
    return None;
}

/*void setButtonAnalogValue(Button button, int analogButtonValue);

void userButtonsAutoCorrect();

int getResistorDeviation();

void setResistorDeviation(const int &resistorDeviation);*/

//////////////////////////////////////PRIVATE METHODS//////////////////////////////////////

bool LcdKeypadShield::isInRarnge(const int &analogValue, const int &etalonValue)
{
    return this->_resistorCurrentDeviation - etalonValue < analogValue && etalonValue + this->_resistorCurrentDeviation > analogValue;
}