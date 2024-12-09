#include "global/vars.h"

#ifndef MESON_BUILD
const char *g_TR2XVersion = "TR2X (non-Docker build)";
#endif

GAME_FLOW_DIR g_GF_OverrideDir = (GAME_FLOW_DIR)-1;

int16_t g_RoomsToDraw[MAX_ROOMS_TO_DRAW] = { 0 };
int16_t g_RoomsToDrawCount = 0;

SDL_Window *g_SDLWindow = NULL;
