#ifndef                     __EVENT__
    #define                 __EVENT__

#include <iostream>

class                       Event
{
    public:
        Event(void); //CTOR
        Event(unsigned int time, const std::string &event); // CUSTOM_CTOR
        ~Event(void); //DTOR
        Event(const Event &other); //COPY_CTOR

        Event               &operator=(const Event &rhs);

        unsigned int        getTime(void) const;
        const std::string   &getEvent(void) const;

        void                setTime(unsigned int time);
        void                setEvent(const std::string &event);

    private:
        unsigned int        _time;
        const std::string   _event;
};

#endif //                   __EVENT__