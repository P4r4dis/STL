#ifndef                             __DOMESTICKOALA__
    #define                         __DOMESTICKOALA__

#include <iostream>
#include <stack>
#include <string>

#include "test_KoalaAction.hpp"

class                               DomesticKoala
{
    private:
        KoalaAction                 _koalaAction;
        // using                       methodPointer_t = void (KoalaAction::*)(const std::string&); // type (scope::namefuction or *)(parameter)
    public:
        DomesticKoala(KoalaAction &koalaAction);
        DomesticKoala(const DomesticKoala &);
        // ~DomesticKoala();

        DomesticKoala               &operator=(const DomesticKoala &);
        KoalaAction                 getKoalaAction(void) const;
};

#endif //                           __DOMESTICKOALA__