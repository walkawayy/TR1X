#pragma once

#include "global/types.h"

void SphereOfDoom_Setup(OBJECT *obj, bool transparent);
void SphereOfDoom_Collision(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);
void SphereOfDoom_Control(int16_t item_num);
void SphereOfDoom_Draw(const ITEM *item);
