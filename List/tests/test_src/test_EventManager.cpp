#include "../test_include/test_EventManager.hpp"

EventManager::EventManager(void) : _emTime(0)
{}

EventManager::~EventManager(void)
{}

EventManager::EventManager(EventManager const &other) :
    _emTime(other._emTime), _containerEvent(other._containerEvent)
{}

EventManager        &EventManager::operator=(EventManager const &rhs)
{
    if (this != &rhs)
    {
        _emTime = rhs._emTime;
        _containerEvent = rhs._containerEvent;
    }

    return *this;
}

unsigned int        EventManager::getEMTime(void) const
{
    return _emTime;
}

std::list<Event>    EventManager::getContainerEvent(void) const
{
    return _containerEvent;
}

void                EventManager::setEMTime(unsigned int time)
{
    _emTime = time;
}