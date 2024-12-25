#pragma once

#include "global/types.h"

void Inv_InitColors(void);
void Inv_Construct(void);
int32_t Inv_Display(int32_t inventory_mode);
int32_t Inv_DisplayKeys(GAME_OBJECT_ID receptacle_type_id);
void Inv_SelectMeshes(INVENTORY_ITEM *inv_item);
int32_t Inv_AnimateInventoryItem(INVENTORY_ITEM *inv_item);
void Inv_DrawInventoryItem(INVENTORY_ITEM *inv_item);
GAME_OBJECT_ID Inv_GetItemOption(GAME_OBJECT_ID object_id);
void Inv_RingIsOpen(RING_INFO *ring);
void Inv_RingIsNotOpen(RING_INFO *ring);
void Inv_RingNotActive(const INVENTORY_ITEM *inv_item);
void Inv_RingActive(void);
void Inv_RemoveInventoryText(void);
