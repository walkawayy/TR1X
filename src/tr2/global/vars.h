#pragma once

#include "global/vars_decomp.h"

#include <libtrx/gfx/context.h>

#include <SDL2/SDL.h>

extern const char *g_TR2XVersion;
extern GAME_FLOW_DIR g_GF_OverrideDir;

extern int16_t g_RoomsToDraw[MAX_ROOMS_TO_DRAW];
extern int16_t g_RoomsToDrawCount;

extern void *g_XBuffer;
extern const float g_RhwFactor;
extern uint16_t *g_TexturePageBuffer16[MAX_TEXTURE_PAGES];
extern PHD_TEXTURE g_TextureInfo[MAX_TEXTURES];

extern SDL_Window *g_SDLWindow;
