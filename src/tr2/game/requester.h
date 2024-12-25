#pragma once

#include "global/types.h"

void Requester_Init(REQUEST_INFO *req);
void Requester_Shutdown(REQUEST_INFO *req);
int32_t Requester_Display(REQUEST_INFO *req, bool destroy, bool backgrounds);
void Requester_RemoveAllItems(REQUEST_INFO *req);
void Requester_Item_CenterAlign(REQUEST_INFO *req, TEXTSTRING *text);
void Requester_Item_LeftAlign(REQUEST_INFO *req, TEXTSTRING *text);
void Requester_Item_RightAlign(REQUEST_INFO *req, TEXTSTRING *text);
void Requester_SetHeading(
    REQUEST_INFO *req, const char *text1, uint32_t flags1, const char *text2,
    uint32_t flags2);
void Requester_ChangeItem(
    REQUEST_INFO *req, int32_t item, const char *text1, uint32_t flags1,
    const char *text2, uint32_t flags2);
void Requester_AddItem(
    REQUEST_INFO *req, const char *text1, uint32_t flags1, const char *text2,
    uint32_t flags2);
void Requester_SetSize(REQUEST_INFO *req, int32_t max_lines, int32_t y_pos);
