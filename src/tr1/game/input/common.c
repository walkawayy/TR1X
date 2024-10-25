#include "game/input/common.h"

#include "config.h"
#include "game/clock.h"
#include "game/input/backends/controller.h"
#include "game/input/backends/keyboard.h"
#include "global/vars.h"

#include <stdint.h>

#define DELAY_FRAMES 12
#define HOLD_FRAMES 3

INPUT_STATE g_Input = { 0 };
INPUT_STATE g_InputDB = { 0 };
INPUT_STATE g_OldInputDB = { 0 };

static int32_t m_HoldBack = 0;
static int32_t m_HoldForward = 0;
static bool m_ListenMode = false;

static INPUT_STATE M_GetDebounced(INPUT_STATE input);
static INPUT_BACKEND_IMPL *M_GetBackend(INPUT_BACKEND backend);
static void M_UpdateFromBackend(
    INPUT_STATE *s, const INPUT_BACKEND_IMPL *backend, int32_t layout);

static INPUT_STATE M_GetDebounced(const INPUT_STATE input)
{
    INPUT_STATE result;
    result.any = input.any & ~g_OldInputDB.any;

    // Allow holding down key to move faster
    const int32_t frame = Clock_GetLogicalFrame();
    if (input.forward || !input.back) {
        m_HoldBack = 0;
    } else if (input.back && m_HoldBack == 0) {
        m_HoldBack = frame;
    } else if (input.back && frame - m_HoldBack >= DELAY_FRAMES + HOLD_FRAMES) {
        result.back = 1;
        result.menu_down = 1;
        m_HoldBack = frame - DELAY_FRAMES;
    }

    if (!input.forward || input.back) {
        m_HoldForward = 0;
    } else if (input.forward && m_HoldForward == 0) {
        m_HoldForward = frame;
    } else if (
        input.forward && frame - m_HoldForward >= DELAY_FRAMES + HOLD_FRAMES) {
        result.forward = 1;
        result.menu_up = 1;
        m_HoldForward = frame - DELAY_FRAMES;
    }

    g_OldInputDB = input;
    return result;
}

static INPUT_BACKEND_IMPL *M_GetBackend(const INPUT_BACKEND backend)
{
    switch (backend) {
    case INPUT_BACKEND_KEYBOARD:
        return &g_Input_Keyboard;
    case INPUT_BACKEND_CONTROLLER:
        return &g_Input_Controller;
    }
    return NULL;
}

static void M_UpdateFromBackend(
    INPUT_STATE *const s, const INPUT_BACKEND_IMPL *const backend,
    const int32_t layout)
{
    // clang-format off
    s->forward                   |= backend->is_pressed(layout, INPUT_ROLE_UP);
    s->back                      |= backend->is_pressed(layout, INPUT_ROLE_DOWN);
    s->left                      |= backend->is_pressed(layout, INPUT_ROLE_LEFT);
    s->right                     |= backend->is_pressed(layout, INPUT_ROLE_RIGHT);
    s->step_left                 |= backend->is_pressed(layout, INPUT_ROLE_STEP_L);
    s->step_right                |= backend->is_pressed(layout, INPUT_ROLE_STEP_R);
    s->slow                      |= backend->is_pressed(layout, INPUT_ROLE_SLOW);
    s->jump                      |= backend->is_pressed(layout, INPUT_ROLE_JUMP);
    s->action                    |= backend->is_pressed(layout, INPUT_ROLE_ACTION);
    s->draw                      |= backend->is_pressed(layout, INPUT_ROLE_DRAW);
    s->look                      |= backend->is_pressed(layout, INPUT_ROLE_LOOK);
    s->roll                      |= backend->is_pressed(layout, INPUT_ROLE_ROLL);
    s->option                    |= backend->is_pressed(layout, INPUT_ROLE_OPTION);
    s->pause                     |= backend->is_pressed(layout, INPUT_ROLE_PAUSE);
    s->toggle_photo_mode         |= backend->is_pressed(layout, INPUT_ROLE_TOGGLE_PHOTO_MODE);
    s->camera_up                 |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_UP);
    s->camera_down               |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_DOWN);
    s->camera_forward            |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_FORWARD);
    s->camera_back               |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_BACK);
    s->camera_left               |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_LEFT);
    s->camera_right              |= backend->is_pressed(layout, INPUT_ROLE_CAMERA_RIGHT);
    s->enter_console             |= backend->is_pressed(layout, INPUT_ROLE_ENTER_CONSOLE);
    s->change_target             |= backend->is_pressed(layout, INPUT_ROLE_CHANGE_TARGET);

    s->item_cheat                |= backend->is_pressed(layout, INPUT_ROLE_ITEM_CHEAT);
    s->fly_cheat                 |= backend->is_pressed(layout, INPUT_ROLE_FLY_CHEAT);
    s->level_skip_cheat          |= backend->is_pressed(layout, INPUT_ROLE_LEVEL_SKIP_CHEAT);
    s->turbo_cheat               |= backend->is_pressed(layout, INPUT_ROLE_TURBO_CHEAT);
    s->health_cheat              |= backend->is_pressed(layout, INPUT_ROLE_HEALTH_CHEAT);

    s->equip_pistols             |= backend->is_pressed(layout, INPUT_ROLE_EQUIP_PISTOLS);
    s->equip_shotgun             |= backend->is_pressed(layout, INPUT_ROLE_EQUIP_SHOTGUN);
    s->equip_magnums             |= backend->is_pressed(layout, INPUT_ROLE_EQUIP_MAGNUMS);
    s->equip_uzis                |= backend->is_pressed(layout, INPUT_ROLE_EQUIP_UZIS);
    s->use_small_medi            |= backend->is_pressed(layout, INPUT_ROLE_USE_SMALL_MEDI);
    s->use_big_medi              |= backend->is_pressed(layout, INPUT_ROLE_USE_BIG_MEDI);

    s->menu_up                   |= backend->is_pressed(layout, INPUT_ROLE_MENU_UP);
    s->menu_down                 |= backend->is_pressed(layout, INPUT_ROLE_MENU_DOWN);
    s->menu_left                 |= backend->is_pressed(layout, INPUT_ROLE_MENU_LEFT);
    s->menu_right                |= backend->is_pressed(layout, INPUT_ROLE_MENU_RIGHT);
    s->menu_confirm              |= backend->is_pressed(layout, INPUT_ROLE_MENU_CONFIRM);
    s->menu_back                 |= backend->is_pressed(layout, INPUT_ROLE_MENU_BACK);

    s->save                      |= backend->is_pressed(layout, INPUT_ROLE_SAVE);
    s->load                      |= backend->is_pressed(layout, INPUT_ROLE_LOAD);

    s->toggle_fps_counter        |= backend->is_pressed(layout, INPUT_ROLE_FPS);
    s->toggle_bilinear_filter    |= backend->is_pressed(layout, INPUT_ROLE_BILINEAR);
    s->toggle_perspective_filter |= backend->is_pressed(layout, INPUT_ROLE_PERSPECTIVE);
    s->toggle_ui                 |= backend->is_pressed(layout, INPUT_ROLE_TOGGLE_UI);
    // clang-format on

    backend->custom_update(s, layout);
}

void Input_Init(void)
{
    if (g_Input_Keyboard.init != NULL) {
        g_Input_Keyboard.init();
    }
    if (g_Input_Controller.init != NULL) {
        g_Input_Controller.init();
    }
}

void Input_Shutdown(void)
{
    if (g_Input_Keyboard.shutdown != NULL) {
        g_Input_Keyboard.shutdown();
    }
    if (g_Input_Controller.shutdown != NULL) {
        g_Input_Controller.shutdown();
    }
}

void Input_InitController(void)
{
    if (g_Input_Controller.init != NULL) {
        g_Input_Controller.init();
    }
}

void Input_ShutdownController(void)
{
    if (g_Input_Controller.shutdown != NULL) {
        g_Input_Controller.shutdown();
    }
}

bool Input_IsRoleRebindable(const INPUT_ROLE role)
{
    return role != INPUT_ROLE_UNBIND_KEY && role != INPUT_ROLE_RESET_BINDINGS
        && role != INPUT_ROLE_HEALTH_CHEAT && role != INPUT_ROLE_PERSPECTIVE
        && role != INPUT_ROLE_MENU_CONFIRM && role != INPUT_ROLE_MENU_BACK
        && role != INPUT_ROLE_MENU_LEFT && role != INPUT_ROLE_MENU_RIGHT
        && role != INPUT_ROLE_MENU_UP && role != INPUT_ROLE_MENU_DOWN;
}

void Input_Update(void)
{
    g_Input.any = 0;

    M_UpdateFromBackend(&g_Input, &g_Input_Keyboard, g_Config.input.layout);
    M_UpdateFromBackend(
        &g_Input, &g_Input_Controller, g_Config.input.cntlr_layout);

    g_Input.camera_reset |= g_Input.look;
    g_Input.menu_up |= g_Input.forward;
    g_Input.menu_down |= g_Input.back;
    g_Input.menu_left |= g_Input.left;
    g_Input.menu_right |= g_Input.right;
    g_Input.menu_back |= g_Input.option;
    g_Input.option &= g_Camera.type != CAM_CINEMATIC;
    g_Input.roll |= g_Input.forward && g_Input.back;
    if (g_Input.left && g_Input.right) {
        g_Input.left = 0;
        g_Input.right = 0;
    }

    if (!g_Config.enable_cheats) {
        g_Input.item_cheat = 0;
        g_Input.fly_cheat = 0;
        g_Input.level_skip_cheat = 0;
        g_Input.turbo_cheat = 0;
        g_Input.health_cheat = 0;
    }

    if (g_Config.enable_tr3_sidesteps) {
        if (g_Input.slow && !g_Input.forward && !g_Input.back
            && !g_Input.step_left && !g_Input.step_right) {
            if (g_Input.left) {
                g_Input.left = 0;
                g_Input.step_left = 1;
            } else if (g_Input.right) {
                g_Input.right = 0;
                g_Input.step_right = 1;
            }
        }
    }

    if (!g_Config.enable_target_change || g_Lara.gun_status != LGS_READY) {
        g_Input.change_target = 0;
    }

    g_InputDB = M_GetDebounced(g_Input);

    if (m_ListenMode) {
        g_Input.any = 0;
        g_InputDB.any = 0;
    }
}

bool Input_IsPressed(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    const INPUT_ROLE role)
{
    return M_GetBackend(backend)->is_pressed(layout, role);
}

bool Input_IsKeyConflicted(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    const INPUT_ROLE role)
{
    return M_GetBackend(backend)->is_role_conflicted(layout, role);
}

bool Input_ReadAndAssignRole(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    const INPUT_ROLE role)
{
    return M_GetBackend(backend)->read_and_assign(layout, role);
}

void Input_UnassignRole(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    const INPUT_ROLE role)
{
    M_GetBackend(backend)->unassign_role(layout, role);
}

const char *Input_GetKeyName(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    const INPUT_ROLE role)
{
    return M_GetBackend(backend)->get_name(layout, role);
}

void Input_ResetLayout(const INPUT_BACKEND backend, const INPUT_LAYOUT layout)
{
    return M_GetBackend(backend)->reset_layout(layout);
}

void Input_EnterListenMode(void)
{
    m_ListenMode = true;
}

void Input_ExitListenMode(void)
{
    m_ListenMode = false;
    Input_Update();
    g_OldInputDB.any = g_Input.any;
    g_InputDB.any = g_Input.any;
}

bool Input_AssignFromJSONObject(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    JSON_OBJECT *const bind_obj)
{
    return M_GetBackend(backend)->assign_from_json_object(layout, bind_obj);
}

bool Input_AssignToJSONObject(
    const INPUT_BACKEND backend, const INPUT_LAYOUT layout,
    JSON_OBJECT *const bind_obj, const INPUT_ROLE role)
{
    return M_GetBackend(backend)->assign_to_json_object(layout, bind_obj, role);
}
