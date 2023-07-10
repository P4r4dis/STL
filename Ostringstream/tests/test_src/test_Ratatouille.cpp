#include "../test_include/test_Ratatouille.hpp"

Ratatouille::Ratatouille(void) :    _vegetable(' '), _condiment(0), _spice(0), _sauce("")
{}

Ratatouille::Ratatouille(Ratatouille const &other) : 
    _vegetable(other._vegetable), _condiment(other._condiment), _spice(other._spice),
    _sauce(other._sauce)
{}

Ratatouille::~Ratatouille(void)
{}

Ratatouille         &Ratatouille::operator=(const Ratatouille &rhs)
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

unsigned char       Ratatouille::getVegetable(void) const
{
    return _vegetable;
}

unsigned int        Ratatouille::getCondiment(void) const
{
    return _condiment;
}

double              Ratatouille::getSpice(void) const
{
    return _spice;
}

std::string         Ratatouille::getSauce(void) const
{
    return _sauce;
}

std::string         Ratatouille::getOstringstream(void) const
{
    return _oss.str();
}

Ratatouille     &Ratatouille::addVegetable(unsigned char vegetable)
{
    _vegetable = vegetable;
    _oss << _vegetable;

    return *this;
}

Ratatouille     &Ratatouille::addCondiment(unsigned int condiment)
{
    _condiment = condiment;
    _oss << _condiment;

    return *this;
}

Ratatouille     &Ratatouille::addSpice(double spice)
{
    _spice = spice;
    _oss << _spice;

    return *this;
}

Ratatouille     &Ratatouille::addSauce(std::string const &sauce)
{
    _sauce = sauce;
    _oss << _sauce;

    return *this;
}

std::string     Ratatouille::kooc(void)
{
    return _oss.str();
}