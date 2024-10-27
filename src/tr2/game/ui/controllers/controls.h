#pragma once

#include "game/input.h"

#include <libtrx/event_manager.h>

typedef enum {
    UI_CONTROLS_STATE_NAVIGATE_LAYOUT,
    UI_CONTROLS_STATE_NAVIGATE_INPUTS,
    UI_CONTROLS_STATE_NAVIGATE_INPUTS_DEBOUNCE,
    UI_CONTROLS_STATE_LISTEN,
    UI_CONTROLS_STATE_LISTEN_DEBOUNCE,
    UI_CONTROLS_STATE_EXIT,
} UI_CONTROLS_STATE;

typedef struct {
    INPUT_BACKEND backend;
    UI_CONTROLS_STATE state;
    int32_t active_layout;
    INPUT_ROLE active_role;
    int32_t active_col;
    int32_t active_row;

    EVENT_MANAGER *events;
} UI_CONTROLS_CONTROLLER;

void UI_ControlsController_Init(UI_CONTROLS_CONTROLLER *controller);
void UI_ControlsController_Shutdown(UI_CONTROLS_CONTROLLER *controller);
bool UI_ControlsController_Control(UI_CONTROLS_CONTROLLER *controller);

INPUT_ROLE UI_ControlsController_GetInputRole(int32_t col, int32_t row);
int32_t UI_ControlsController_GetInputRoleCount(int32_t col);
