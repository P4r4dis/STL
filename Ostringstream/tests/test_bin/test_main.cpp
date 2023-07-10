#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <cstdlib>

#include "../test_include/test_Ratatouille.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Event, test_Event_constructor, .init = redirect_all_stdout)
{
    cr_assert(1 == 1);
}
