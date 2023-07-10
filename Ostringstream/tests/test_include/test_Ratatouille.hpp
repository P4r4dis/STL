#ifndef                 __RATATOUILLE__
    #define             __RATATOUILLE__

#include <iostream>
class                   Ratatouille
{
    public:
        Ratatouille(void);
        Ratatouille(Ratatouille const &other);
        ~Ratatouille(void);

        Ratatouille     &operator=(const Ratatouille &rhs);

        unsigned char   getVegetable(void) const;
        unsigned int    getCondiment(void) const;
        double          getSpice(void) const;
        std::string     getSauce(void) const;
    private:
        unsigned char   _vegetable;
        unsigned int    _condiment;
        double          _spice;
        std::string     _sauce;

};
#endif //               __RATATOUILLE__