#include "game/inventory/inventory_vars.h"

#include "global/types.h"

#include <stddef.h>
#include <stdint.h>

int16_t g_InvKeysCurrent;
int16_t g_InvKeysObjects;
int16_t g_InvKeysQtys[24] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

INVENTORY_ITEM *g_InvKeysList[23] = {
    &g_InvItemLeadBar,
    &g_InvItemPuzzle1,
    &g_InvItemPuzzle2,
    &g_InvItemPuzzle3,
    &g_InvItemPuzzle4,
    &g_InvItemKey1,
    &g_InvItemKey2,
    &g_InvItemKey3,
    &g_InvItemKey4,
    &g_InvItemPickup1,
    &g_InvItemPickup2,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

int16_t g_InvMainCurrent;
int16_t g_InvMainObjects = 1;
int16_t g_InvMainQtys[24] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

INVENTORY_ITEM *g_InvMainList[23] = {
    &g_InvItemCompass,
    &g_InvItemPistols,
    &g_InvItemShotgun,
    &g_InvItemMagnum,
    &g_InvItemUzi,
    &g_InvItemGrenade,
    &g_InvItemBigMedi,
    &g_InvItemMedi,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

int16_t g_InvOptionCurrent;
int16_t g_InvOptionObjects = 5;
INVENTORY_ITEM *g_InvOptionList[] = {
    &g_InvItemGame,    &g_InvItemControls,  &g_InvItemSound,
    &g_InvItemDetails, &g_InvItemLarasHome,
};

INVENTORY_ITEM g_InvItemCompass = {
    .object_id = O_MAP_OPTION,
    .frames_total = 25,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 10,
    .anim_direction = 1,
    .pt_xrot_sel = 4352,
    .pt_xrot = 0,
    .x_rot_sel = -8192,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 456,
    .ztrans = 0,
    .which_meshes = 0x5,
    .drawn_meshes = 0x5,
    .inv_pos = 0,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemMedi = {
    .object_id = O_MEDI_OPTION,
    .frames_total = 26,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 25,
    .anim_direction = 1,
    .pt_xrot_sel = 4032,
    .pt_xrot = 0,
    .x_rot_sel = -7296,
    .x_rot = 0,
    .y_rot_sel = -4096,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 216,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 7,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemBigMedi = {
    .object_id = O_BIGMEDI_OPTION,
    .frames_total = 20,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 19,
    .anim_direction = 1,
    .pt_xrot_sel = 3616,
    .pt_xrot = 0,
    .x_rot_sel = -8160,
    .x_rot = 0,
    .y_rot_sel = -4096,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 352,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 6,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemLeadBar = {
    .object_id = O_LEADBAR_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 3616,
    .pt_xrot = 0,
    .x_rot_sel = -8160,
    .x_rot = 0,
    .y_rot_sel = -4096,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 352,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 100,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPickup1 = {
    .object_id = O_PICKUP_OPTION_1,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 111,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPickup2 = {
    .object_id = O_PICKUP_OPTION_2,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 110,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemScion = {
    .object_id = O_SCION_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 109,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPuzzle1 = {
    .object_id = O_PUZZLE_OPTION_1,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 108,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPuzzle2 = {
    .object_id = O_PUZZLE_OPTION_2,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 107,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPuzzle3 = {
    .object_id = O_PUZZLE_OPTION_3,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 106,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPuzzle4 = {
    .object_id = O_PUZZLE_OPTION_4,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 105,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemKey1 = {
    .object_id = O_KEY_OPTION_1,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 101,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemKey2 = {
    .object_id = O_KEY_OPTION_2,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 102,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemKey3 = {
    .object_id = O_KEY_OPTION_3,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 103,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemKey4 = {
    .object_id = O_KEY_OPTION_4,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 7200,
    .pt_xrot = 0,
    .x_rot_sel = -4352,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 256,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 104,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPistols = {
    .object_id = O_PISTOL_OPTION,
    .frames_total = 12,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 11,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 1,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemShotgun = {
    .object_id = O_SHOTGUN_OPTION,
    .frames_total = 13,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 12,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = 0,
    .x_rot = 0,
    .y_rot_sel = -8192,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 2,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemMagnum = {
    .object_id = O_MAGNUM_OPTION,
    .frames_total = 12,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 11,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 3,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemUzi = {
    .object_id = O_UZI_OPTION,
    .frames_total = 13,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 12,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 4,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemGrenade = {
    .object_id = O_EXPLOSIVE_OPTION,
    .frames_total = 15,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 14,
    .anim_direction = 1,
    .pt_xrot_sel = 5024,
    .pt_xrot = 0,
    .x_rot_sel = 0,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 368,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 5,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemPistolAmmo = {
    .object_id = O_PISTOL_AMMO_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 1,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemShotgunAmmo = {
    .object_id = O_SG_AMMO_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 2,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemMagnumAmmo = {
    .object_id = O_MAG_AMMO_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 3,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemUziAmmo = {
    .object_id = O_UZI_AMMO_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 3200,
    .pt_xrot = 0,
    .x_rot_sel = -3808,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 296,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 4,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemGame = {
    .object_id = O_PASSPORT_CLOSED,
    .frames_total = 30,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 14,
    .anim_direction = 1,
    .pt_xrot_sel = 4640,
    .pt_xrot = 0,
    .x_rot_sel = -4320,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 384,
    .ztrans = 0,
    .which_meshes = 0x13,
    .drawn_meshes = 0x13,
    .inv_pos = 0,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemDetails = {
    .object_id = O_DETAIL_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 4224,
    .pt_xrot = 0,
    .x_rot_sel = -6720,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 424,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 1,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemSound = {
    .object_id = O_SOUND_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 4832,
    .pt_xrot = 0,
    .x_rot_sel = -2336,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 368,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 2,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemControls = {
    .object_id = O_CONTROL_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 5504,
    .pt_xrot = 0,
    .x_rot_sel = 1536,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 352,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 3,
    .sprlist = NULL,
};

INVENTORY_ITEM g_InvItemLarasHome = {
    .object_id = O_PHOTO_OPTION,
    .frames_total = 1,
    .current_frame = 0,
    .goal_frame = 0,
    .open_frame = 0,
    .anim_direction = 1,
    .pt_xrot_sel = 4640,
    .pt_xrot = 0,
    .x_rot_sel = -4320,
    .x_rot = 0,
    .y_rot_sel = 0,
    .y_rot = 0,
    .ytrans_sel = 0,
    .ytrans = 0,
    .ztrans_sel = 384,
    .ztrans = 0,
    .which_meshes = 0xFFFFFFFF,
    .drawn_meshes = 0xFFFFFFFF,
    .inv_pos = 5,
    .sprlist = NULL,
};