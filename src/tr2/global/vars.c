#include "global/vars.h"

#ifndef MESON_BUILD
const char *g_TR2XVersion = "TR2X (non-Docker build)";
#endif

GAME_FLOW_DIR g_GF_OverrideDir = (GAME_FLOW_DIR)-1;

int16_t g_RoomsToDraw[MAX_ROOMS_TO_DRAW] = { 0 };
int16_t g_RoomsToDrawCount = 0;

void *g_XBuffer = NULL;
const float g_RhwFactor = 0x14000000.p0;
uint16_t *g_TexturePageBuffer16[MAX_TEXTURE_PAGES] = { 0 };
PHD_TEXTURE g_TextureInfo[MAX_TEXTURES];

SDL_Window *g_SDLWindow = NULL;
