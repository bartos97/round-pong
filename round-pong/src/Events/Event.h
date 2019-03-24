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
    virtual EventCode getType() const noexcept = 0;
};