#include "LcdKeypadShield.h"
#include "WemosD1R1Pins.h"

LcdKeypadShield::LcdKeypadShield(const uint8_t &rs,const  uint8_t &enable, 
                                const uint8_t &d4,const  uint8_t &d5,const  uint8_t &d6,const  uint8_t &d7) : 
                                LiquidCrystal(rs, enable, d4, d5, d6, d7)
{
}

LcdKeypadShield::~LcdKeypadShield()
{
}

LcdKeypadShield LcdKeypadShield::createByBoaard(const BoardType &board)
{
    switch (board)
    {
    case UNO:
        return LcdKeypadShield(8,9,4,5,6,7);
        break;

    case WemosD1R1:
        return LcdKeypadShield(D8,D9,D4,D5,D6,D7);
        break;
    }

    return LcdKeypadShield(0,0,0,0,0,0);
}