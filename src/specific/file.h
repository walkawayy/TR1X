#ifndef T1M_SPECIFIC_FILE_H
#define T1M_SPECIFIC_FILE_H

#include <stdio.h>

// clang-format off
#define _fread                  ((size_t        __cdecl(*)(void *, size_t, size_t, FILE *))0x00442C20)
#define LoadLevel               ((int           __cdecl(*)(const char *path, int level_id))0x0041AFB0)
// clang-format on

int32_t __cdecl LoadRooms(FILE* fp);
int32_t __cdecl LoadObjects(FILE* fp);
int32_t __cdecl LoadItems(FILE* handle);
int32_t __cdecl S_LoadLevel(int level_id);
const char* __cdecl GetFullPath(const char* filename);
void __cdecl FindCdDrive();

#ifdef T1M_FEAT_LEVEL_FIXES
void FixPyramidSecretTrigger();
int32_t GetSecretCount();
#endif

void T1MInjectSpecificFile();

#endif
