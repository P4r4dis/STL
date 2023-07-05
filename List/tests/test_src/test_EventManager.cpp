#include "../test_include/test_EventManager.hpp"

EventManager::EventManager(void) : _currentTime(0)
{}

EventManager::~EventManager(void)
{}

EventManager::EventManager(EventManager const &other) :
    _currentTime(other._currentTime), _containerEvent(other._containerEvent)
{}

EventManager        &EventManager::operator=(EventManager const &rhs)
{
    if (this != &rhs)
    {
        _currentTime = rhs._currentTime;
        _containerEvent = rhs._containerEvent;
    }

    return *this;
}

void                EventManager::addEvent(const Event &e)
{
    if (e.getTime() >= _currentTime) 
    {
        auto it = _containerEvent.begin();
        while ((it != _containerEvent.end()) && (it->getTime() <= e.getTime()))
            ++it;
        // auto it = std::find_if(_containerEvent.begin(), _containerEvent.end(), [&e](const Event& event) {
        //     return  event.getTime() > e.getTime();
        // });
        _containerEvent.insert(it, e);
    }
}

unsigned int        EventManager::getEMTime(void) const
{
    return _currentTime;
}

std::list<Event>    EventManager::getContainerEvent(void) const
{
    return _containerEvent;
}

void                EventManager::setEMTime(unsigned int time)
{
    _currentTime = time;
}