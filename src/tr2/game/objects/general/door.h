#pragma once

#include "global/types.h"

typedef enum {
    DOOR_STATE_CLOSED = 0,
    DOOR_STATE_OPEN = 1,
} DOOR_STATE;

void Door_Shut(DOORPOS_DATA *d);
void Door_Open(DOORPOS_DATA *d);

void Door_Setup(OBJECT *obj);

void Door_Initialise(int16_t item_num);
void Door_Control(int16_t item_num);
void Door_Collision(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);
