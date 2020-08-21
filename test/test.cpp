//
// Created by Felix Weidinger  on 20/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//
#include "iostream"
#include "LCD.h"
#include "pigpio.h"

int main() {



    std::cout<<"STUPID HOBBITS!"<<std::endl;
    std::cout<<gpioInitialise()<<std::endl;
    LCD lcd(7, 8, 25, 24, 23, 18);
    lcd.initialiseLCD();
    std::cout<<LCD::LCDModes::LCD_COMMAND_MODE<<std::endl;
    lcd.setText("Hello World!", LCD::LCD_LINE_1);
    gpioTerminate();
}