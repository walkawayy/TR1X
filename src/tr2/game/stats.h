#pragma once

#include "global/types.h"

void Stats_StartTimer(void);
void Stats_UpdateTimer(void);
void Stats_Reset(void);
FINAL_STATS Stats_ComputeFinalStats(void);
int32_t Stats_StoreAssaultTime(uint32_t time);
