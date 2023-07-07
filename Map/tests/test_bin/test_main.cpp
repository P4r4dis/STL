#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <cstdlib>

#include "../test_include/test_BF_Translator.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Event, test_Event_constructor, .init = redirect_all_stdout)
{
    BF_Translator   bf;

    cr_assert(bf.translate("inputFile",
    "outputFile.c") == 0);

     // Chemin vers le fichier source C à compiler
    std::string cSourceFile = "outputFile.c";

    // Nom du fichier exécutable généré après compilation
    // std::string executableFile = "executable";

    // Commande pour compiler le fichier source C en un exécutable
    std::string compileCommand = "gcc " + cSourceFile;// + " -o " + executableFile;

    // Exécution de la commande de compilation en utilisant la fonction system()
    int compileResult = system(compileCommand.c_str());
    cr_assert(compileResult == 0);

    // Commande pour exécuter le fichier exécutable
    std::string executeCommand = "./a.out";//+ executableFile;

    // Exécution de la commande pour exécuter le fichier exécutable
    int executeResult = system(executeCommand.c_str());
    cr_assert(executeResult == 0);


    // if (compileResult == 0) {
    //     std::cout << "Compilation successful!" << std::endl;

    //     // Commande pour exécuter le fichier exécutable
    //     std::string executeCommand = "./a.out";//+ executableFile;

    //     // Exécution de la commande pour exécuter le fichier exécutable
    //     int executeResult = system(executeCommand.c_str());

    //     if (executeResult == 0) {
    //         std::cout << "\nExecution successful!" << std::endl;
    //     } else {
    //         std::cerr << "Execution failed!" << std::endl;
    //     }
    // } else {
    //     std::cerr << "Compilation failed!" << std::endl;
    // }

    cr_assert_stdout_eq_str("Hello World");
}
