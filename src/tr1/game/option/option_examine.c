#include "game/option/option_examine.h"

#include "game/input.h"
#include "game/ui/widgets/paginator.h"

#include <libtrx/game/objects/names.h>
#include <libtrx/game/ui/common.h>

#define MAX_LINES 10

static UI_WIDGET *m_PaginatorUI = nullptr;

static void M_End(void);

static void M_End(void)
{
    m_PaginatorUI->free(m_PaginatorUI);
    m_PaginatorUI = nullptr;
}

bool Option_Examine_CanExamine(const GAME_OBJECT_ID object_id)
{
    return Object_GetDescription(object_id) != nullptr;
}

bool Option_Examine_IsActive(void)
{
    return m_PaginatorUI != nullptr;
}

void Option_Examine_Control(const GAME_OBJECT_ID object_id)
{
    if (m_PaginatorUI == nullptr) {
        m_PaginatorUI = UI_Paginator_Create(
            Object_GetName(object_id), Object_GetDescription(object_id),
            MAX_LINES);
    }

    m_PaginatorUI->control(m_PaginatorUI);

    if (g_InputDB.menu_back || g_InputDB.menu_confirm) {
        M_End();
    }
}

void Option_Examine_Draw(void)
{
    if (m_PaginatorUI != nullptr) {
        m_PaginatorUI->draw(m_PaginatorUI);
    }
}

void Option_Examine_Shutdown(void)
{
    if (m_PaginatorUI != nullptr) {
        M_End();
    }
}
