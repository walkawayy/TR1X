#include "game/objects/traps/pendulum.h"

#include "game/items.h"
#include "game/lara/control.h"
#include "game/random.h"
#include "game/room.h"
#include "game/spawn.h"

#include <libtrx/game/lara/common.h>

#define PENDULUM_DAMAGE 50

void Pendulum_Control(const int16_t item_num)
{
    ITEM *const item = Item_Get(item_num);

    if (item->touch_bits != 0) {
        Lara_TakeDamage(PENDULUM_DAMAGE, true);

        const ITEM *const lara_item = Lara_GetItem();
        const XYZ_32 pos = {
            .x = lara_item->pos.x + (Random_GetControl() - 0x4000) / 256,
            .z = lara_item->pos.z + (Random_GetControl() - 0x4000) / 256,
            .y = lara_item->pos.y - Random_GetControl() / 44,
        };
        Spawn_Blood(
            pos.x, pos.y, pos.z, lara_item->speed,
            lara_item->rot.y + (Random_GetControl() - 0x4000) / 8,
            lara_item->room_num);
    }

    const SECTOR *const sector =
        Room_GetSector(item->pos.x, item->pos.y, item->pos.z, &item->room_num);
    item->floor = Room_GetHeight(sector, item->pos.x, item->pos.y, item->pos.z);
    Item_Animate(item);
}

void Pendulum_Setup(OBJECT *const obj)
{
    obj->control = Pendulum_Control;
    obj->collision = Object_Collision;
    obj->shadow_size = 128;
    obj->save_flags = 1;
    obj->save_anim = 1;
}
