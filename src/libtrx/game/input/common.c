#include "game/input/common.h"

#include "game/clock.h"
#include "game/game_string.h"
#include "game/input/backends/controller.h"
#include "game/input/backends/keyboard.h"

#include <stdint.h>

INPUT_STATE g_Input = { 0 };
INPUT_STATE g_InputDB = { 0 };
INPUT_STATE g_OldInputDB = { 0 };

static bool m_ListenMode = false;

static bool m_IsRoleHardcoded[INPUT_ROLE_NUMBER_OF] = {
    0,
#if TR_VERSION == 1
    [INPUT_ROLE_UNBIND_KEY] = 1,
    [INPUT_ROLE_RESET_BINDINGS] = 1,
    [INPUT_ROLE_PERSPECTIVE] = 1,
#endif
    [INPUT_ROLE_MENU_CONFIRM] = 1,
    [INPUT_ROLE_MENU_BACK] = 1,
    [INPUT_ROLE_MENU_LEFT] = 1,
    [INPUT_ROLE_MENU_RIGHT] = 1,
    [INPUT_ROLE_MENU_UP] = 1,
    [INPUT_ROLE_MENU_DOWN] = 1,
};

static const GAME_STRING_ID m_LayoutMap[INPUT_LAYOUT_NUMBER_OF] = {
    [INPUT_LAYOUT_DEFAULT] = GS_ID(CONTROL_DEFAULT_KEYS),
    [INPUT_LAYOUT_CUSTOM_1] = GS_ID(CONTROL_CUSTOM_1),
    [INPUT_LAYOUT_CUSTOM_2] = GS_ID(CONTROL_CUSTOM_2),
    [INPUT_LAYOUT_CUSTOM_3] = GS_ID(CONTROL_CUSTOM_3),
};

static INPUT_BACKEND_IMPL *M_GetBackend(INPUT_BACKEND backend);

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
    return !m_IsRoleHardcoded[role];
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

bool Input_IsInListenMode(void)
{
    return m_ListenMode;
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

const char *Input_GetLayoutName(const INPUT_LAYOUT layout)
{
    return GameString_Get(m_LayoutMap[layout]);
}
