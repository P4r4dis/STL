#include "../test_include/test_Event.hpp"

Event::Event(void) : _time(0), _event("")
{}

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event)
{}

Event::~Event(void)
{}

Event::Event(const Event &other) : _time(other._time), _event(other._event)
{}

Event               &Event::operator=(const Event &rhs)
{
    if (this != &rhs)
    {
        _time = rhs._time;
        _event = rhs._event;
    }

    return *this;
}

unsigned int        Event::getTime(void) const
{
    return _time;
}

const std::string   &Event::getEvent(void) const
{
    return _event;
}

void                Event::setTime(unsigned int time)
{
    _time = time;
}

void                Event::setEvent(const std::string &event)
{
    _event = event;
}