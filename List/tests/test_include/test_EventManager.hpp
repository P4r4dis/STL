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
};
#endif //                   __EVENTMANAGER__