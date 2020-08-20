//
// Created by Felix Weidinger  on 19/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//

#ifndef LIBLCD1602_LCD_H
#define LIBLCD1602_LCD_H

#include <cstdint>
#include <string>
#include <map>


/**
 * @brief Result Codes for LCD specific stuff.
 */
typedef enum {

    LCD_RESULT_SUCCES = 0,
    LCD_RESULT_ERROR_UNKNOWN = -1,
    LCD_RESULT_ERROR_DANGEROUS = -2,
    LCD_RESULT_ERROR_LINE_OUT_OF_BOUNDS=-3,
    GPIO_ERROR=-4
} LCDResult_t;


/**
 *  Models the lcd.
 *  Currently only supports 4Bit mode.
 *  R/W -> grounded
 */
class LCD {
public:
    enum LCDLines {
        LCD_LINE_1 = 0x80,
        LCD_LINE_2 = 0xC0
    };
    enum LCDModes {
        LCD_COMMAND_MODE = 0,
        LCD_CHARACTER_MODE = 1
    };

    LCD(const int &pinRegisterSelect, const int& pinEnable,const int &pinDataBit4, const int &pinDataBit5,
        const int &pinDataBit6, const int &pinDataBit7);

    LCDResult_t initialiseLCD();

    LCDResult_t writeLCD(const uint8_t& byte,LCDModes lcdmode);

    LCDResult_t setText(const std::string &text, LCDLines line);

    void toggleEnablePin() const;

private:
    // PIN DEFINITIONS
    const int PIN_REGISTER_SELECT;
    const int PIN_DATA_BIT_4;
    const int PIN_DATA_BIT_5;
    const int PIN_DATA_BIT_6;
    const int PIN_DATA_BIT_7;
    const int PIN_ENABLE;
    //DEVICE CONSTANTS
    static const int LCD_CHARS_PER_LINE = 16;


};

#endif //LIBLCD1602_LCD_H
