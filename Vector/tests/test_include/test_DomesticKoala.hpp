#ifndef                             __DOMESTICKOALA__
    #define                         __DOMESTICKOALA__

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include "test_KoalaAction.hpp"

class                                                       DomesticKoala
{
    private:
        KoalaAction                                         _koalaAction;
        using                                               methodPointer_t = void (KoalaAction::*)(const std::string&); // type (scope::namefuction or *)(parameter)
        std::vector<methodPointer_t>                        _action;
    public:
        DomesticKoala(KoalaAction &koalaAction);
        DomesticKoala(const DomesticKoala &);
        ~DomesticKoala();

        DomesticKoala                                       &operator=(const DomesticKoala & rhs);
        KoalaAction                                         getKoalaAction(void) const;
        void                                                learnAction(unsigned char command, methodPointer_t action);
        const std::vector<methodPointer_t>                  *getActions(void) const;
        void                                                unlearnAction(unsigned char command);
        void                                                doAction(unsigned char command, const std::string& param);
        void                                                setKoalaAction(KoalaAction &koalaAction);
};

#endif //                           __DOMESTICKOALA__