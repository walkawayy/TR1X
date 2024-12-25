#pragma once

#include "global/types.h"

void Inv_Ring_SetRequestedObjectID(const GAME_OBJECT_ID object_id);
void Inv_Ring_Init(
    RING_INFO *ring, RING_TYPE type, INVENTORY_ITEM **list, int16_t qty,
    int16_t current, IMOTION_INFO *imo);
void Inv_Ring_GetView(const RING_INFO *ring, PHD_3DPOS *view);
void Inv_Ring_Light(const RING_INFO *ring);
void Inv_Ring_CalcAdders(RING_INFO *ring, int16_t rotation_duration);
void Inv_Ring_DoMotions(RING_INFO *ring);
void Inv_Ring_RotateLeft(RING_INFO *ring);
void Inv_Ring_RotateRight(RING_INFO *ring);
void Inv_Ring_MotionInit(
    RING_INFO *ring, int16_t frames, RING_STATUS status,
    RING_STATUS status_target);
void Inv_Ring_MotionSetup(
    RING_INFO *ring, RING_STATUS status, RING_STATUS status_target,
    int16_t frames);
void Inv_Ring_MotionRadius(RING_INFO *ring, int16_t target);
void Inv_Ring_MotionRotation(RING_INFO *ring, int16_t rotation, int16_t target);
void Inv_Ring_MotionCameraPos(RING_INFO *ring, int16_t target);
void Inv_Ring_MotionCameraPitch(RING_INFO *ring, int16_t target);
void Inv_Ring_MotionItemSelect(RING_INFO *ring, const INVENTORY_ITEM *inv_item);
void Inv_Ring_MotionItemDeselect(
    RING_INFO *ring, const INVENTORY_ITEM *inv_item);
