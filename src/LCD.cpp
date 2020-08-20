//
// Created by Felix Weidinger  on 19/08/2020.
// Copyright (c) 2020  Felix Weidinger
// All rights reserved.
//

#include "LCD.h"

LCD::LCD(const uint8_t &pinRegisterSelect, const uint8_t &pinDataBit4, const uint8_t &pinDataBit5,
         const uint8_t &pinDataBit6, const uint8_t &pinDataBit7) : PIN_REGISTER_SELECT(pinRegisterSelect),
                                                                   PIN_DATA_BIT_4(pinDataBit4),
                                                                   PIN_DATA_BIT_5(pinDataBit5),
                                                                   PIN_DATA_BIT_6(pinDataBit6),
                                                                   PIN_DATA_BIT_7(pinDataBit7) {
}

