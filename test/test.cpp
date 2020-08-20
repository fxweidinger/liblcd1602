//
// Created by Felix Weidinger  on 20/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//
#include "LCD.h"
#include "pigpio.h"

int main() {

    gpioInitialise();
    LCD *lcd = new LCD(7, 8, 25, 24, 23, 18);
    lcd->initialiseLCD();
    lcd->setText("WICHSE", LCD::LCD_LINE_2);
    gpioTerminate();
}