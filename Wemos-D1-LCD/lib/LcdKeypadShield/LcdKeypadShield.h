#include <LiquidCrystal.h>
#include "BoardType.h"

class LcdKeypadShield
{
private:

    LiquidCrystal * lcd = nullptr;

public:

    //Connecting the shield directly to the board
    LcdKeypadShield(BoardType board);

    //Arbitrary connection of pins to LCD
    LcdKeypadShield(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

    ~LcdKeypadShield();
};