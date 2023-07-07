#include "../include/BF_Translator.hpp"

int     main()
{
    BF_Translator   bf;

    bf.translate("inputFile", "outputFile.c");
    return 0;
}

