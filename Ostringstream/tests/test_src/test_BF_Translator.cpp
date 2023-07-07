#include "../test_include/test_BF_Translator.hpp"

int         BF_Translator::translate(const std::string &in, const std::string &out)
{
        std::ifstream inputFile(in);
        if (!inputFile) {
            std::cerr << "Error opening input file: " << in << std::endl;
            return -1;
        }

        std::ofstream outputFile(out);
        if (!outputFile) {
            std::cerr << "Error opening output file: " << out << std::endl;
            inputFile.close();
            return -1;
        }

    outputFile  << "#include <stdio.h>" << std::endl
                << "int main(void)" << std::endl
                << "{" << std::endl
                << "char array[60000] = \"\";" << std::endl
                << "char *ptr = array;" << std::endl;
                
    std::map<char, std::string> instructions = 
    {
        {'+', "++*ptr;\n"},
        {'-', "--*ptr;\n"},
        {'>', "++ptr;\n"},
        {'<', "--ptr;\n"},
        {'.', "putchar(*ptr);\n"},
        {',', "*ptr = getchar();\n"},
        {'[', "while (*ptr) {\n"},
        {']', "}\n",}
    };

    std::string line;
    while (std::getline(inputFile, line))
    {
        for (unsigned int i = 0; i < line.size(); i++)
        {
            outputFile << instructions[line[i]];
        }
    }

    outputFile  << "return 0;" << std::endl
                << "}" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}