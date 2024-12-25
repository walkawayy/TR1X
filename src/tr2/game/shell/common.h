#pragma once

#include "global/types.h"

#include <libtrx/game/shell.h>

void Shell_Main(void);
void Shell_Start();

const char *Shell_GetGameflowPath(void);
void Shell_ProcessEvents(void);

bool Shell_IsFullscreen(void);

void Shell_GoFullscreen(void);
void Shell_GoMaximized(void);
void Shell_GoWindowed(int32_t x, int32_t y, int32_t width, int32_t height);
