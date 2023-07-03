#include "../include/DomesticKoala.hpp"


DomesticKoala::DomesticKoala(KoalaAction &kAction)  :   _koalaAction(kAction), _action(256)
{}

DomesticKoala::DomesticKoala(const DomesticKoala& obj) : _koalaAction(obj._koalaAction), _action(obj._action)
{}

DomesticKoala::~DomesticKoala(void)
{
}

DomesticKoala   &DomesticKoala::operator=(const DomesticKoala& rhs)
{
    _koalaAction = rhs._koalaAction;
    _action = rhs._action;
    return *this;
}

KoalaAction     DomesticKoala::getKoalaAction(void) const
{
    return _koalaAction;
}


const std::vector<DomesticKoala::methodPointer_t>  *DomesticKoala::getActions(void) const
{
    return &_action;
}

void            DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _action.at(command) = action;
}

void            DomesticKoala::unlearnAction(unsigned char command)
{
    _action[command] = nullptr;
}

void            DomesticKoala::doAction(unsigned char command, const std::string& param)
{
    if (_action[command] != nullptr)
        (_koalaAction.*_action[command])(param);
}

void            DomesticKoala::setKoalaAction(KoalaAction &koalaAction)
{
    _koalaAction = koalaAction;
}