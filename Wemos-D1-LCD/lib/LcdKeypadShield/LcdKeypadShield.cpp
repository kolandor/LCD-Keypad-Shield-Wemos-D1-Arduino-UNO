#include "LcdKeypadShield.h"

LcdKeypadShield::LcdKeypadShield(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : lcd(rs, enable, d4, d5, d6, d7)
{
    
}

LcdKeypadShield::~LcdKeypadShield()
{
}