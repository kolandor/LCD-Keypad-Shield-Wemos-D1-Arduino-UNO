#include <LiquidCrystal.h>
#include "BoardType.h"

class LcdKeypadShield : public LiquidCrystal
{
private:

public:
    //Arbitrary connection of pins to LCD
    LcdKeypadShield(const uint8_t &rs,const uint8_t &enable, 
                    const uint8_t &d4,const  uint8_t &d5,const uint8_t &d6,const uint8_t &d7);

    ~LcdKeypadShield();

    //Connecting the shield directly to the board
    static LcdKeypadShield createByBoaard(const BoardType &board);
};