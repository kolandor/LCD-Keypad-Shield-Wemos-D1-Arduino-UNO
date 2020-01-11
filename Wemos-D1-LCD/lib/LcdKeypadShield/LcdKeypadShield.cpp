#include "LcdKeypadShield.h"
#include "WemosD1R1Pins.h"

LcdKeypadShield::LcdKeypadShield(BoardType board)
{
    switch (board)
    {
    case UNO:
        LcdKeypadShield(8,9,4,5,6,7);
        break;

    case WemosD1R1:
        LcdKeypadShield(D8,D9,D4,D5,D6,D7);
        break;
    }
}

LcdKeypadShield::LcdKeypadShield(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
    this->lcd = new LiquidCrystal(rs, enable, d4, d5, d6, d7);
}

LcdKeypadShield::~LcdKeypadShield()
{
    if(this->lcd != nullptr)
    {
        delete this->lcd;
    }
}