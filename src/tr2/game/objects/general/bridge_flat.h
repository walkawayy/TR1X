#pragma once

#include "global/types.h"

void __cdecl BridgeFlat_Floor(
    ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);

void __cdecl BridgeFlat_Ceiling(
    ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);