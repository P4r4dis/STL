#ifndef                 __MUTANTSTACK__
    #define             __MUTANTSTACK__

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class                   MutantStack
{
    public:
        MutantStack(void);
        MutantStack(const MutantStack<T> &obj);
        ~MutantStack(void);
    
    private:
        std::stack<T>      _stack;



};

template <typename T>
MutantStack<T>::MutantStack(void)
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj)
{
    _stack = obj._stack;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{}

#endif //               __MUTANTSTACK__