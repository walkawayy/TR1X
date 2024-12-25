#pragma once

#include "global/types.h"

void Lara_Draw(const ITEM *item);
void Lara_Draw_I(
    const ITEM *item, const FRAME_INFO *frame1, const FRAME_INFO *frame2,
    int32_t frac, int32_t rate);
