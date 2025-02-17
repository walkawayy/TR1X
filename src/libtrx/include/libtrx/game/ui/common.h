#pragma once

#include "./events.h"

typedef enum {
    UI_KEY_UP,
    UI_KEY_DOWN,
    UI_KEY_LEFT,
    UI_KEY_RIGHT,
    UI_KEY_HOME,
    UI_KEY_END,
    UI_KEY_BACK,
    UI_KEY_RETURN,
    UI_KEY_ESCAPE,
} UI_INPUT;

void UI_Init(void);
void UI_Shutdown(void);
void UI_ToggleState(bool *config_setting);

void UI_HandleKeyDown(uint32_t key);
void UI_HandleKeyUp(uint32_t key);
void UI_HandleTextEdit(const char *text);
void UI_HandleLayoutChange(void);

extern int32_t UI_GetCanvasWidth(void);
extern int32_t UI_GetCanvasHeight(void);
extern UI_INPUT UI_TranslateInput(uint32_t system_keycode);
