#include "../test_include/test_DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &kAction)  :   _koalaAction(kAction)
{}

DomesticKoala::DomesticKoala(const DomesticKoala& obj) : _koalaAction(obj._koalaAction)
{}

KoalaAction     DomesticKoala::getKoalaAction(void) const
{
    return _koalaAction;
}