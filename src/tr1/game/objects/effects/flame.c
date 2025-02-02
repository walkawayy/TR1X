#include "game/objects/effects/flame.h"

#include "game/collide.h"
#include "game/effects.h"
#include "game/lara/common.h"
#include "game/lara/control.h"
#include "game/room.h"
#include "game/sound.h"
#include "global/vars.h"

#define FLAME_ONFIRE_DAMAGE 5
#define FLAME_TOONEAR_DAMAGE 3

void Flame_Setup(OBJECT *obj)
{
    obj->control = Flame_Control;
}

void Flame_Control(int16_t effect_num)
{
    EFFECT *effect = Effect_Get(effect_num);

    effect->frame_num--;
    if (effect->frame_num <= Object_GetObject(O_FLAME)->mesh_count) {
        effect->frame_num = 0;
    }

    if (effect->counter < 0) {
        if (g_Lara.water_status == LWS_CHEAT) {
            effect->counter = 0;
            Sound_StopEffect(SFX_FIRE, nullptr);
            Effect_Kill(effect_num);
            return;
        }

        effect->pos.x = 0;
        effect->pos.y = 0;
        if (effect->counter == -1) {
            effect->pos.z = -100;
        } else {
            effect->pos.z = 0;
        }

        Collide_GetJointAbsPosition(
            g_LaraItem, &effect->pos, -1 - effect->counter);

        int32_t y = Room_GetWaterHeight(
            g_LaraItem->pos.x, g_LaraItem->pos.y, g_LaraItem->pos.z,
            g_LaraItem->room_num);

        if (y != NO_HEIGHT && effect->pos.y > y) {
            effect->counter = 0;
            Sound_StopEffect(SFX_FIRE, nullptr);
            Effect_Kill(effect_num);
        } else {
            if (effect->room_num != g_LaraItem->room_num) {
                Effect_NewRoom(effect_num, g_LaraItem->room_num);
            }
            Sound_Effect(SFX_FIRE, &effect->pos, SPM_NORMAL);
            Lara_TakeDamage(FLAME_ONFIRE_DAMAGE, true);
        }
        return;
    }

    Sound_Effect(SFX_FIRE, &effect->pos, SPM_NORMAL);
    if (effect->counter) {
        effect->counter--;
    } else if (Lara_IsNearItem(&effect->pos, 600)) {
        if (g_Lara.water_status == LWS_CHEAT) {
            return;
        }

        int32_t x = g_LaraItem->pos.x - effect->pos.x;
        int32_t z = g_LaraItem->pos.z - effect->pos.z;
        int32_t distance = SQUARE(x) + SQUARE(z);

        Lara_TakeDamage(FLAME_TOONEAR_DAMAGE, true);

        if (distance < SQUARE(300)) {
            effect->counter = 100;

            effect_num = Effect_Create(g_LaraItem->room_num);
            if (effect_num != NO_EFFECT) {
                effect = Effect_Get(effect_num);
                effect->frame_num = 0;
                effect->object_id = O_FLAME;
                effect->counter = -1;
            }
        }
    }
}
