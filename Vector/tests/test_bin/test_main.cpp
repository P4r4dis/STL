#include "../test_include/test_DomesticKoala.hpp"
#include "../test_include/test_KoalaAction.hpp"

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

Test(Parser, test_Vector_main)//, .init = redirect_all_stdout)
{
    KoalaAction     action ;
    DomesticKoala   dk(action);

    dk.learnAction('<', &KoalaAction::eat);
    dk.learnAction('>', &KoalaAction::goTo);
    dk.learnAction('#', &KoalaAction::sleep);
    dk.learnAction('X', &KoalaAction::reproduce);

    dk.doAction('>', "{EPITECH.}");
    dk.doAction('<', "a DoubleCheese");
    dk.doAction('X', "a Seagull");
    dk.doAction('#', "The end of the C++ pool, and an Astek burning on a stake");
}