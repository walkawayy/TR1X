#pragma once

#include "global/types.h"

void Keyhole_Setup(OBJECT *obj);

void Keyhole_Collision(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);

int32_t Keyhole_Trigger(int16_t item_num);
