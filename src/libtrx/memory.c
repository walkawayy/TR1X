#include "memory.h"

#include "debug.h"

#include <stdlib.h>
#include <string.h>

void *Memory_Alloc(const size_t size)
{
    void *result = malloc(size);
    ASSERT(result != nullptr);
    memset(result, 0, size);
    return result;
}

void *Memory_Realloc(void *const memory, const size_t size)
{
    void *result = realloc(memory, size);
    ASSERT(result != nullptr);
    return result;
}

void Memory_Free(void *const memory)
{
    if (memory != nullptr) {
        free(memory);
    }
}

void Memory_FreePointer(void *arg)
{
    ASSERT(arg != nullptr);
    void *memory;
    memcpy(&memory, arg, sizeof(void *));
    memcpy(arg, &(void *) { nullptr }, sizeof(void *));
    Memory_Free(memory);
}

char *Memory_Dup(const char *const buffer, const size_t size)
{
    ASSERT(buffer != nullptr);
    char *memory = Memory_Alloc(size);
    memcpy(memory, buffer, size);
    return memory;
}

char *Memory_DupStr(const char *const string)
{
    ASSERT(string != nullptr);
    char *memory = Memory_Alloc(strlen(string) + 1);
    strcpy(memory, string);
    return memory;
}
