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
            it++;
        // auto it = std::find_if(_containerEvent.begin(), _containerEvent.end(), [&e](const Event& event) {
        //     return  event.getTime() >= e.getTime();
        // });
        _containerEvent.insert(it, e);
    }
}

void                EventManager::removeEventsAt(unsigned int time)
{
    if (!_containerEvent.empty())
    {
        auto it = _containerEvent.begin();
        while (it != _containerEvent.end())
        {
            if (it->getTime() == time)
                it = _containerEvent.erase(it);
            else
                it++;
        }

    }
}

void                EventManager::dumpEvents(void) const
{
    for (auto event : _containerEvent) 
    {
        std::cout << event.getTime() << ": " << event.getEvent() << std::endl;
    }
}

void                EventManager::dumpEventAt(unsigned int time) const
{
    for (auto event : _containerEvent) 
    {
        if (event.getTime() == time)
            std::cout << event.getTime() << ": " << event.getEvent() << std::endl;
    }
}

void                EventManager::addTime(unsigned int time)
{
    unsigned int newTime = _currentTime + time;

    for (auto event : _containerEvent) 
    {
        if (event.getTime() > _currentTime && event.getTime() <= newTime)
        {
            std::cout << event.getEvent() << std::endl;
        }
    }
    _currentTime = newTime;
    if (!_containerEvent.empty())
    {
        auto it = _containerEvent.begin();
        while (it != _containerEvent.end())
        {
            if (it->getTime() <= _currentTime)
                it = _containerEvent.erase(it);
            else
                it++;
        }
    }
}

void                EventManager::addEventList(const std::list<Event> &events)
{
    for (const auto &event : events)
        addEvent(event);
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