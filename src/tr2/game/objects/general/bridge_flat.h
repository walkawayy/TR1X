#pragma once

#include "global/types.h"

void BridgeFlat_Setup(void);

void BridgeFlat_Floor(
    const ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);

void BridgeFlat_Ceiling(
    const ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);
