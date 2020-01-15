#include "LcdKeypadShield.h"
#include "WemosD1R1Pins.h"

//////////////////////////////////////PUBLIC METHODS//////////////////////////////////////

LcdKeypadShield::LcdKeypadShield(const uint8_t &rs,const  uint8_t &enable, 
                                const uint8_t &d4,const  uint8_t &d5,const  uint8_t &d6,const  uint8_t &d7, const int &aBtnPin) : 
                                LiquidCrystal(rs, enable, d4, d5, d6, d7)
{
    this->_analogBtnPin = aBtnPin;
    this->_resistorCurrentDeviation = LcdKeypadShield::_defaultResistorCurrentDeviation;
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
    return !isInRange(analogRead(this->_analogBtnPin), (int)LcdKeypadShield::_noKeyAnalogValue);
}

Button LcdKeypadShield::getButton()
{
    int analogValue = analogRead(this->_analogBtnPin);

    if (!isInRange(analogValue, (int)LcdKeypadShield::_noKeyAnalogValue))
    {
        for (size_t btnIndex = 0; btnIndex < LcdKeypadShield::_buttonsCount; btnIndex++)
        {
            if (isInRange(analogValue, this->_buttonsValues[btnIndex]))
            {
                return static_cast<Button>(btnIndex);
            }
        }
    }
    
    return None;
}

void LcdKeypadShield::setButtonAnalogValue(const Button &button,const int &analogButtonValue)
{
    this->_buttonsValues[static_cast<int>(button)] = analogButtonValue;
}

int LcdKeypadShield::getResistorDeviation()
{
    return this->_resistorCurrentDeviation;
}

void LcdKeypadShield::setResistorDeviation(const int &resistorDeviation)
{
    this->_resistorCurrentDeviation = resistorDeviation;
}

/*void LcdKeypadShield::userButtonsAutoCorrect()
{

}*/

//////////////////////////////////////PRIVATE METHODS//////////////////////////////////////

bool LcdKeypadShield::isInRange(const int &analogValue,const int &etalonValue)
{
    return this->_resistorCurrentDeviation - etalonValue < analogValue && etalonValue + this->_resistorCurrentDeviation > analogValue;
}

int LcdKeypadShield::getAverageBtnValue()
{
    const int checkIterations = 10;

    int analogBtnValue = 0;

    int iterator = 0;
    
    int analogValue = 0;
    
    while (iterator < checkIterations)
    {
        analogValue = analogRead(this->_analogBtnPin);

        if (!isInRange(analogValue, (int)LcdKeypadShield::_noKeyAnalogValue))
        {
            bool isNotContain = true;

            for (size_t btnIndex = 0; btnIndex < LcdKeypadShield::_buttonsCount; btnIndex++)
            {
                if (isInRange(analogValue, this->_buttonsValues[btnIndex]))
                {
                    isNotContain = false;
                    break;
                }
            }

            if (isNotContain)
            {
                analogBtnValue += analogValue;
                iterator++;
            }
        }
        delay(300);
    }

    return analogBtnValue / checkIterations;
}