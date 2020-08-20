//
// Created by Felix Weidinger  on 19/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//

#ifndef LIBLCD1602_LCD_H
#define LIBLCD1602_LCD_H


#include <cstdint>
//#include "pigpio.h"

/**
 *  Models the lcd.
 *  Currently only supports 4Bit mode.
 *  R/W -> grounded
 */
class LCD {
public:
    LCD(const uint8_t &pinRegisterSelect, const uint8_t &pinDataBit4, const uint8_t &pinDataBit5,
        const uint8_t &pinDataBit6, const uint8_t &pinDataBit7);

    void initialiseLCD();

    void writeToLCD();

private:
    // PIN DEFINITIONS
    const uint8_t PIN_REGISTER_SELECT;
    const uint8_t PIN_DATA_BIT_4;
    const uint8_t PIN_DATA_BIT_5;
    const uint8_t PIN_DATA_BIT_6;
    const uint8_t PIN_DATA_BIT_7;
    //DEVICE CONSTANTS
    static const uint8_t LCD_CHARACTER_MODE = 1;
    static const uint8_t LCD_COMMAND_MODE = 0;
    static const uint8_t LCD_CHARS_PER_LINE =16;
    static const uint8_t LCD_LINE_1=0x80;
    static const uint8_t LCD_LINE_2=0xC0;

};

#endif //LIBLCD1602_LCD_H
