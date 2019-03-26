#pragma once


/**
 * Unique integer codes for all events
 */
enum class EventCode
{
    None = 0,
    WindowClose, WindowResize,
    KeyPress, KeyRelease, KeyRepeat,
    MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
};


/**
 * Interface for all events
 */
class Event
{
public:
    bool m_isHandled = false;
    virtual EventCode getType() const noexcept = 0;

#ifdef RP_DEBUG
    virtual const char* getName() const noexcept = 0;
#endif // RP_DEBUG
};


/**
 * Macro with definitions of common events functions
 */
#ifdef RP_DEBUG
    #define EVENT_GET_INFO_IMPL(x) \
        virtual EventCode getType() const noexcept override { return EventCode::##x; } \
        virtual const char* getName() const noexcept { return #x; }
#elif RP_RELEASE
    #define EVENT_GET_INFO_IMPL(x) \
        virtual EventCode getType() const noexcept override { return EventCode::##x; }
#endif // RP_DEBUG