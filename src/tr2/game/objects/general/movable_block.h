#pragma once

#include "global/types.h"

int32_t MovableBlock_TestDestination(const ITEM *item, int32_t block_height);

int32_t MovableBlock_TestPush(
    const ITEM *item, int32_t block_height, uint16_t quadrant);

int32_t MovableBlock_TestPull(
    const ITEM *item, int32_t block_height, uint16_t quadrant);

void MovableBlock_Initialise(int16_t item_num);

void MovableBlock_Control(int16_t item_num);

void MovableBlock_Collision(int16_t item_num, ITEM *lara_item, COLL_INFO *coll);

void MovableBlock_Draw(const ITEM *item);

void MovableBlock_Setup(OBJECT *obj);
