#pragma once

#include "global/types.h"

#define INPUT_MAX_LAYOUT 2

typedef enum {
    // clang-format off
    INPUT_ROLE_UP          = 0,
    INPUT_ROLE_FORWARD     = INPUT_ROLE_UP,
    INPUT_ROLE_DOWN        = 1,
    INPUT_ROLE_BACK        = INPUT_ROLE_DOWN,
    INPUT_ROLE_LEFT        = 2,
    INPUT_ROLE_RIGHT       = 3,
    INPUT_ROLE_STEP_LEFT   = 4,
    INPUT_ROLE_STEP_RIGHT  = 5,
    INPUT_ROLE_SLOW        = 6,
    INPUT_ROLE_JUMP        = 7,
    INPUT_ROLE_ACTION      = 8,
    INPUT_ROLE_DRAW_WEAPON = 9,
    INPUT_ROLE_FLARE       = 10,
    INPUT_ROLE_LOOK        = 11,
    INPUT_ROLE_ROLL        = 12,
    INPUT_ROLE_OPTION      = 13,
    INPUT_ROLE_CONSOLE     = 14,
    INPUT_ROLE_NUMBER_OF   = 15,
    // clang-format on
} INPUT_ROLE;

typedef union {
    uint64_t any;
    struct {
        // clang-format off
        uint64_t forward: 1;
        uint64_t back: 1;
        uint64_t left: 1;
        uint64_t right: 1;
        uint64_t jump: 1;
        uint64_t draw: 1;
        uint64_t action: 1;
        uint64_t slow: 1;
        uint64_t option: 1;
        uint64_t look: 1;
        uint64_t step_left: 1;
        uint64_t step_right: 1;
        uint64_t roll: 1;
        uint64_t pause: 1;
        uint64_t reserved1: 1;
        uint64_t reserved2: 1;
        uint64_t dozy_cheat: 1;
        uint64_t stuff_cheat: 1;
        uint64_t debug_info: 1;
        uint64_t flare: 1;
        uint64_t menu_confirm: 1;
        uint64_t menu_back: 1;
        uint64_t save: 1;
        uint64_t load: 1;
        uint64_t console: 1;
        // clang-format on
    };
} INPUT_STATE;

typedef struct {
    uint16_t key[INPUT_ROLE_NUMBER_OF];
} INPUT_LAYOUT;

extern INPUT_STATE g_Input;
extern INPUT_STATE g_InputDB;
extern INPUT_STATE g_OldInputDB;
extern INPUT_LAYOUT g_Layout[2];
extern bool g_ConflictLayout[INPUT_ROLE_NUMBER_OF];

bool Input_Update(void);

void Input_EnterListenMode(void);
void Input_ExitListenMode(void);
bool Input_IsAnythingPressed(void);
void Input_AssignKey(int32_t layout, INPUT_ROLE role, uint16_t key);
uint16_t Input_GetAssignedKey(int32_t layout, INPUT_ROLE role);

const char *Input_GetLayoutName(int32_t layout);
const char *Input_GetRoleName(INPUT_ROLE role);
const char *Input_GetKeyName(uint16_t key);

void __cdecl Input_CheckConflictsWithDefaults(void);
