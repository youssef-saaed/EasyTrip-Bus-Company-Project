#include "Event.h"

Event::Event(char Type, Time EventTime)
{
    this->Type = Type;
    this->EventTime = EventTime;
}

Time Event::getEventTime() const
{
    return EventTime;
}

char Event::getType()
{
    return Type;
}
