#pragma once

#include <libtrx/game/gamebuf.h>

#include <stdint.h>

void GameBuf_Init(int32_t cap);
void GameBuf_Reset(void);
void GameBuf_Shutdown(void);
void GameBuf_Free(size_t free_size);
