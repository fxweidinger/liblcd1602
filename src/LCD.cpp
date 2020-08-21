//
// Created by Felix Weidinger  on 19/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//

#include "LCD.h"
#include "pigpio.h"

/**
 * Simple Constructor
 */
LCD::LCD(const int &pinRegisterSelect, const int &pinEnable, const int &pinDataBit4,
         const int &pinDataBit5,
         const int &pinDataBit6, const int &pinDataBit7) : PIN_REGISTER_SELECT(pinRegisterSelect),
                                                           PIN_ENABLE(pinEnable),
                                                           PIN_DATA_BIT_4(pinDataBit4),
                                                           PIN_DATA_BIT_5(pinDataBit5),
                                                           PIN_DATA_BIT_6(pinDataBit6),
                                                           PIN_DATA_BIT_7(pinDataBit7) {
}

LCDResult_t LCD::initialiseLCD() {

    gpioSetMode(PIN_ENABLE, PI_OUTPUT);
    gpioSetMode(PIN_REGISTER_SELECT, PI_OUTPUT);
    gpioSetMode(PIN_DATA_BIT_4, PI_OUTPUT);
    gpioSetMode(PIN_DATA_BIT_5, PI_OUTPUT);
    gpioSetMode(PIN_DATA_BIT_6, PI_OUTPUT);
    gpioSetMode(PIN_DATA_BIT_7, PI_OUTPUT);

    writeLCD(0x33, LCD_COMMAND_MODE);
    writeLCD(0x32, LCD_COMMAND_MODE);
    writeLCD(0x06, LCD_COMMAND_MODE);
    writeLCD(0x0C, LCD_COMMAND_MODE);
    writeLCD(0x28, LCD_COMMAND_MODE);
    writeLCD(0x01, LCD_COMMAND_MODE);
    time_sleep(0.005);
    return LCD_RESULT_SUCCES;
}



LCDResult_t LCD::writeLCD(uint8_t byte, LCD::LCDModes lcdmode) {
    gpioWrite(PIN_REGISTER_SELECT, lcdmode);

    gpioWrite(PIN_DATA_BIT_4, 0);
    gpioWrite(PIN_DATA_BIT_5, 0);
    gpioWrite(PIN_DATA_BIT_6, 0);
    gpioWrite(PIN_DATA_BIT_7, 0);

    if ((byte & 0x10) == 0x10)
        gpioWrite(PIN_DATA_BIT_4, 1);
    if ((byte & 0x20) == 0x20)
        gpioWrite(PIN_DATA_BIT_5, 1);
    if ((byte & 0x30) == 0x30)
        gpioWrite(PIN_DATA_BIT_6, 1);
    if ((byte & 0x40) == 0x40)
        gpioWrite(PIN_DATA_BIT_7, 1);

    toggleEnablePin();

    gpioWrite(PIN_DATA_BIT_4, 0);
    gpioWrite(PIN_DATA_BIT_5, 0);
    gpioWrite(PIN_DATA_BIT_6, 0);
    gpioWrite(PIN_DATA_BIT_7, 0);


    if ((byte & 0x01) == 0x01)
        gpioWrite(PIN_DATA_BIT_4, 1);
    if ((byte & 0x02) == 0x02)
        gpioWrite(PIN_DATA_BIT_5, 1);
    if ((byte & 0x03) == 0x03)
        gpioWrite(PIN_DATA_BIT_6, 1);
    if ((byte & 0x04) == 0x04)
        gpioWrite(PIN_DATA_BIT_7, 1);
    toggleEnablePin();
    return LCD_RESULT_SUCCES;
}

void LCD::toggleEnablePin() {
    time_sleep(0.005);
    gpioWrite(PIN_ENABLE, 1);
    time_sleep(0.005);
    gpioWrite(PIN_ENABLE, 0);
    time_sleep(0.005);
}

LCDResult_t LCD::setText(const std::string &text, LCD::LCDLines line) {

    writeLCD(line, LCD::LCD_COMMAND_MODE);

    for (uint8_t i : text) {
        writeLCD(i, LCD::LCD_CHARACTER_MODE);
    }
    return LCD_RESULT_SUCCES;
}

