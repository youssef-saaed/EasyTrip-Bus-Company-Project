#include "Event.h"

Event::Event(char Type, Time EventTime)
{
    this->Type = Type;
    this->EventTime = EventTime;
}

Time Event::getEventTime()
{
    return EventTime;
}

char Event::getType()
{
    return Type;
}