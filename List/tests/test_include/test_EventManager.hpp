#ifndef                     __EVENTMANAGER__
    #define                 __EVENTMANAGER__
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "test_Event.hpp"


class                       EventManager
{
    public:
        EventManager(void); //CTOR
        ~EventManager(void); //DTOR
        EventManager(EventManager const &other); //COPY_CTOR

        EventManager        &operator=(EventManager const &rhs);

        void                addEvent(const Event &e);
        void                removeEventsAt(unsigned int time);
        void                dumpEvents(void) const;
        void                dumpEventsAt(unsigned int time) const;
        void                addTime(unsigned int time);
        void                addEventList(std::list<Event> &events);

        unsigned int        getEMTime(void) const;
        std::list<Event>    getContainerEvent(void) const;

        void                setEMTime(unsigned int time);
    
    private:
        unsigned int        _currentTime;
        std::list<Event>    _containerEvent;
};
#endif //                   __EVENTMANAGER__