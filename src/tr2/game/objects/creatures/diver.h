#pragma once

#include <stdint.h>

int32_t Diver_GetWaterSurface(
    int32_t x, int32_t y, int32_t z, int16_t room_num);

void Diver_Setup(void);

void Diver_Control(int16_t item_num);

int16_t Diver_Harpoon(
    int32_t x, int32_t y, int32_t z, int16_t speed, int16_t y_rot,
    int16_t room_num);
