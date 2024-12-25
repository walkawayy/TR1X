#pragma once

#include "global/types.h"

void XianSpearman_Setup(void);
void XianSpearman_DoDamage(
    const ITEM *item, CREATURE *creature, int32_t damage);
void XianSpearman_Control(int16_t item_num);
