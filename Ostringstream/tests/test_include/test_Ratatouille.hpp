#ifndef                 __RATATOUILLE__
    #define             __RATATOUILLE__

#include <iostream>
#include <sstream>
class                       Ratatouille
{
    public:
        Ratatouille(void);
        Ratatouille(Ratatouille const &other);
        ~Ratatouille(void);

        Ratatouille         &operator=(const Ratatouille &rhs);

        unsigned char       getVegetable(void) const;
        unsigned int        getCondiment(void) const;
        double              getSpice(void) const;
        std::string         getSauce(void) const;
        std::string         getOstringstream(void) const;

        Ratatouille         &addVegetable(unsigned char vegetable);
        std::string         kooc(void);
    private:
        unsigned char       _vegetable;
        unsigned int        _condiment;
        double              _spice;
        std::string         _sauce;
        std::ostringstream  _oss;

};
#endif //               __RATATOUILLE__