#include "../test_include/test_Parser.hpp"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Parser, test_Parser)//, .init = redirect_all_stdout)
{
    Parser p;
    cr_assert(p.result() == 0);
}

Test(Parser, test_Parser_feed)//, .init = redirect_all_stdout)
{
    Parser p;

    p.feed("((12*2)+14)");
    std::cout << p.result() << std::endl;
    cr_assert(p.result() == 38);
    p.feed("((17 % 9) / 4)");
    std::cout << p.result() << std::endl;
    cr_assert(p.result() == 40);
    p.reset();
    cr_assert(p.result() == 0);
    p.feed("(17 - (4 * 13))");
    std::cout << p.result() << std::endl;
    cr_assert(p.result() == -35);
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
    std::cout << p.result() << std::endl;
    cr_assert(p.result() == 861);
}