#include "game/ui/events.h"

#include "config/common.h"
#include "debug.h"
#include "game/ui/common.h"

static EVENT_MANAGER *m_EventManager = nullptr;

static void M_HandleConfigChange(const EVENT *event, void *data);

static void M_HandleConfigChange(const EVENT *const event, void *const data)
{
    if (m_EventManager != nullptr) {
        const EVENT new_event = {
            .name = "canvas_resize",
            .sender = nullptr,
            .data = nullptr,
        };
        EventManager_Fire(m_EventManager, &new_event);
        UI_HandleLayoutChange();
    }
}

void UI_Events_Init(void)
{
    m_EventManager = EventManager_Create();
    Config_SubscribeChanges(M_HandleConfigChange, nullptr);
}

void UI_Events_Shutdown(void)
{
    EventManager_Free(m_EventManager);
    m_EventManager = nullptr;
}

int32_t UI_Events_Subscribe(
    const char *const event_name, const UI_WIDGET *const sender,
    const EVENT_LISTENER listener, void *const user_data)
{
    ASSERT(m_EventManager != nullptr);
    return EventManager_Subscribe(
        m_EventManager, event_name, sender, listener, user_data);
}

void UI_Events_Unsubscribe(const int32_t listener_id)
{
    if (m_EventManager != nullptr) {
        EventManager_Unsubscribe(m_EventManager, listener_id);
    }
}

void UI_Events_Fire(const EVENT *const event)
{
    if (m_EventManager != nullptr) {
        EventManager_Fire(m_EventManager, event);
    }
}
