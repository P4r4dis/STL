#ifndef                             __KOALAACTION__
    #define                         __KOALAACTION__

#include <iostream>
#include <stack>
#include <string>

class                               KoalaAction
{
    private:
    public:
        KoalaAction(void);

        void                        eat(const std::string &str);
        void                        goTo(const std::string &str);
        void                        sleep(const std::string &str);
        void                        reproduce(const std::string &str);
};

#endif //                           __KOALAACTION__