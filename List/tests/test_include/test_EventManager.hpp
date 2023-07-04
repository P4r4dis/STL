#ifndef                     __EVENTMANAGER__
    #define                 __EVENTMANAGER__
#include <list>
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
        void                dumpEvent(void) const;
        void                dumpEventsAt(unsigned int time) const;
        void                addTime(unsigned int time);
        void                addEventList(std::list<Event> &events);

        unsigned int        getEMTime(void) const;
        std::list<Event>    getContainerEvent(void) const;

        void                setEMTime(unsigned int time);
    
    private:
        unsigned int        _emTime;
        std::list<Event>    _containerEvent;
};
#endif //                   __EVENTMANAGER__