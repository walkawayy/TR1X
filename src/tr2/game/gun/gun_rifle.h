#pragma once

#include "global/types.h"

void Gun_Rifle_DrawMeshes(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_UndrawMeshes(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_Ready(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_Control(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_FireShotgun(void);
void Gun_Rifle_FireM16(bool running);
void Gun_Rifle_FireHarpoon(void);
void Gun_Rifle_FireGrenade(void);
void Gun_Rifle_Draw(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_Undraw(LARA_GUN_TYPE weapon_type);
void Gun_Rifle_Animate(LARA_GUN_TYPE weapon_type);
