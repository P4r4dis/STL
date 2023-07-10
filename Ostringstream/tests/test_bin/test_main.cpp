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

Test(Ratatouille, test_Ratatouille_constructor)//, .init = redirect_all_stdout)
{
    Ratatouille     rat;

    cr_assert(rat.getVegetable() == ' ');
    cr_assert(rat.getCondiment() == 0);
    cr_assert(rat.getSpice() == 0);
    cr_assert(rat.getSauce() == "");

    Ratatouille     copyRat(rat);

    cr_assert(copyRat.getVegetable() == ' ');
    cr_assert(copyRat.getCondiment() == 0);
    cr_assert(copyRat.getSpice() == 0);
    cr_assert(copyRat.getSauce() == "");

    Ratatouille     rat2;

    rat2 = rat;
    cr_assert(rat2.getVegetable() == ' ');
    cr_assert(rat2.getCondiment() == 0);
    cr_assert(rat2.getSpice() == 0);
    cr_assert(rat2.getSauce() == "");
}

Test(Ratatouille, test_Ratatouille_addVegetable)//, .init = redirect_all_stdout)
{
    Ratatouille     rat;

    rat.addVegetable('T');

    cr_assert(rat.getOstringstream() == "T");
    cr_assert(rat.kooc() == "T");
}

Test(Ratatouille, test_Ratatouille_addCondiment)//, .init = redirect_all_stdout)
{
    Ratatouille     rat;
    
    rat.addVegetable('T').addCondiment(42);
    cr_assert(rat.getOstringstream() == "T42");
}

Test(Ratatouille, test_Ratatouille_addSpice)//, .init = redirect_all_stdout)
{
    Ratatouille     rat;
    
    rat.addVegetable('T').addCondiment(42).addSpice(123.321);
    cr_assert(rat.getOstringstream() == "T42123.321");
}

Test(Ratatouille, test_Ratatouille_addSauce)//, .init = redirect_all_stdout)
{
    Ratatouille     rat;
    
    rat.addVegetable('T').addCondiment(42).addSpice(123.321).addSauce("Tomato");
    cr_assert(rat.getOstringstream() == "T42123.321Tomato");
}

Test(Ratatouille, test_main)
{
    Ratatouille     rata;

    rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
    rata.addVegetable('x');
    std::cout << "We taste: " << rata.kooc() << std::endl;
    rata.addSauce("Bolognese");
    rata.addSpice(3.14);
    std::cout << "C'mon, taste that: " << rata.kooc() << std::endl;
    // C'mon , gimme your pot , i'll just take a bit of it and try something else
    Ratatouille     glurp(rata);
    glurp.addVegetable('p');
    glurp.addVegetable('o');
    glurp.addSauce("Tartar");
    std::cout << "And now: " << glurp.kooc() << std::endl;
    // Looks good ...
    rata = glurp;
    std::cout << "I'll taste again, it's sooo good: " << rata.kooc() << std::endl;
    // return 0;
}