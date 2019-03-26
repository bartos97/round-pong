#pragma once


/**
 * Unique integer codes for all events
 */
enum class EventCode
{
    none = 0,
    windowClose, windowResize,
    keyPress, keyRelease,
    mouseClick, mouseRelease, mouseMove, mouseScroll
};


/**
 * Interface for all events
 */
class Event
{
public:
    bool m_isHandled = false;

#ifdef RP_DEBUG
    virtual EventCode getType() const noexcept = 0;
    virtual const char* getName() const noexcept = 0;
#endif // RP_DEBUG
};


#ifdef RP_DEBUG
    #define EVENT_GET_INFO_IMPL(x) \
        virtual EventCode getType() const noexcept override { return EventCode::##x; } \
        virtual const char* getName() const noexcept { return #x; }
#elif RP_RELEASE
    #define EVENT_GET_INFO_IMPL(x)
#endif // RP_DEBUG


//class EventDispatcher
//{
//public:
//    EventDispatcher(Event& event);
//    bool dispatch();
//
//private:
//    Event& m_event;
//};