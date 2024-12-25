#pragma once

#include "global/types.h"

void LOT_InitialiseArray(void);
void LOT_DisableBaddieAI(int16_t item_num);
bool LOT_EnableBaddieAI(int16_t item_num, bool always);
void LOT_InitialiseSlot(int16_t item_num, int32_t slot);
void LOT_CreateZone(ITEM *item);
void LOT_ClearLOT(LOT_INFO *LOT);
