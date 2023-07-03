#include "../include/KoalaAction.hpp"


KoalaAction::KoalaAction(void)
{}

void    KoalaAction::eat(const std::string &str)
{
    std::cout << "I eat: " << str << std::endl;
}

void    KoalaAction::goTo(const std::string &str)
{
    std::cout << "I go to: " << str << std::endl;
}

void    KoalaAction::sleep(const std::string &str)
{
    std::cout << "I sleep, and dream of: " << str << std::endl;
}

void    KoalaAction::reproduce(const std::string &str)
{
    std::cout << "I attempt to reproduce with: " << str << std::endl;
}