#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <cstdlib>

#include "../test_include/test_MutantStack.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(MutantStack, test_constructor)
{
    MutantStack<int> mstack;

    MutantStack<int> copyMstack(mstack);
}

Test(MutantStack, test_begin)
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push (0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end_it = mstack.end();
    ++it;
    --it;
    while (it != end_it)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

Test(MutantStack, test_main)
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push (0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end_it = mstack.end();
    ++it;
    --it;
    while (it != end_it)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}