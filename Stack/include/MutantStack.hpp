#ifndef                 __MUTANTSTACK__
    #define             __MUTANTSTACK__

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class                   MutantStack : public std::stack<T>, public std::stack<T>::container_type::iterator
{
    public:
        MutantStack(void);
        MutantStack(const MutantStack<T> &obj);
        ~MutantStack(void);

        std::stack<T>::container_type::iterator    begin(void);
        std::stack<T>::container_type::iterator    end(void);
};

template <typename T>
MutantStack<T>::MutantStack(void)
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj), std::stack<T>::container_type::iterator(obj)
{
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{}

template <typename T>
std::stack<T>::container_type::iterator    MutantStack<T>::begin(void)
{
    return std::stack<T>::c.begin();
}

template <typename T>
std::stack<T>::container_type::iterator    MutantStack<T>::end(void)
{
    return std::stack<T>::c.end();
}

#endif //               __MUTANTSTACK__