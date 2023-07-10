#include "../test_include/test_Ratatouille.hpp"

Ratatouille::Ratatouille(void) :    _vegetable(' '), _condiment(0), _spice(0), _sauce("")
{}

Ratatouille::Ratatouille(Ratatouille const &other) : 
    _vegetable(other._vegetable), _condiment(other._condiment), _spice(other._spice),
    _sauce(other._sauce)
{}

Ratatouille::~Ratatouille(void)
{}

Ratatouille     &Ratatouille::operator=(const Ratatouille &rhs)
{
    if (this != &rhs)
    {
        _vegetable = rhs._vegetable;
        _condiment = rhs._condiment;
        _spice = rhs._spice;
        _sauce = rhs._sauce;
    }
    return *this;
}

unsigned char   Ratatouille::getVegetable(void) const
{
    return _vegetable;
}

unsigned int    Ratatouille::getCondiment(void) const
{
    return _condiment;
}

double          Ratatouille::getSpice(void) const
{
    return _spice;
}

std::string     Ratatouille::getSauce(void) const
{
    return _sauce;
}