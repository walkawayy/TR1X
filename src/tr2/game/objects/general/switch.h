#pragma once

#include "global/types.h"

void Switch_Setup(OBJECT *obj, bool underwater);

void Switch_Collision(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);

void Switch_CollisionUW(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);

void Switch_Control(int16_t item_num);

int32_t Switch_Trigger(int16_t item_num, int16_t timer);
