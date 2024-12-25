#pragma once

#include <stdint.h>

void ShowGymStatsText(const char *time_str, int32_t type);
void ShowStatsText(const char *time_str, int32_t type);
void ShowEndStatsText(void);

int32_t LevelStats(int32_t level_num);
int32_t GameStats(int32_t level_num);
int32_t AddAssaultTime(uint32_t time);
