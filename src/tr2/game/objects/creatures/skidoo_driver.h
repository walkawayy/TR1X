#pragma once

#include <stdint.h>

#define SKIDOO_DRIVER_HITPOINTS 100

void SkidooDriver_Setup(void);
void SkidooDriver_Initialise(int16_t item_num);
void SkidooDriver_Control(int16_t item_num);
