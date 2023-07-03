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

Test(KoalaAction, test_KoalaAction, .init = redirect_all_stdout)
{
    KoalaAction action;

    action.goTo("{EPITECH.}");
    action.eat("a DoubleCheese");
    action.reproduce("a Seagull");
    action.sleep("The end of the C++ pool, and an Astek burning on a stake");

    cr_assert_stdout_eq_str("I go to: {EPITECH.}\n\
I eat: a DoubleCheese\n\
I attempt to reproduce with: a Seagull\n\
I sleep, and dream of: The end of the C++ pool, and an Astek burning on a stake\n");
}

Test(DomesticKoala, test_Vector_DomesticKoala, .init = redirect_all_stdout)
{
    KoalaAction     action;
    DomesticKoala   dk(action);

    dk.getKoalaAction().goTo("{EPITECH.}");
    dk.getKoalaAction().eat("a DoubleCheese");
    dk.getKoalaAction().reproduce("a Seagull");
    dk.getKoalaAction().sleep("The end of the C++ pool, and an Astek burning on a stake");

    cr_assert_stdout_eq_str("I go to: {EPITECH.}\n\
I eat: a DoubleCheese\n\
I attempt to reproduce with: a Seagull\n\
I sleep, and dream of: The end of the C++ pool, and an Astek burning on a stake\n");
}

Test(DomesticKoala, test_Vector_DomesticKoala_copyConstructor, .init = redirect_all_stdout)
{
    KoalaAction     action;
    DomesticKoala   dk(action);
    DomesticKoala   copyDk(dk);

    copyDk.getKoalaAction().goTo("{EPITECH.}");
    copyDk.getKoalaAction().eat("a DoubleCheese");
    copyDk.getKoalaAction().reproduce("a Seagull");
    copyDk.getKoalaAction().sleep("The end of the C++ pool, and an Astek burning on a stake");

    cr_assert_stdout_eq_str("I go to: {EPITECH.}\n\
I eat: a DoubleCheese\n\
I attempt to reproduce with: a Seagull\n\
I sleep, and dream of: The end of the C++ pool, and an Astek burning on a stake\n");
}

Test(DomesticKoala, test_Vector_main)//, .init = redirect_all_stdout)
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