#ifndef                             __PARSER__
    #define                         __PARSER__

#include <iostream>
#include <stack>
#include <string>

class                               Parser
{
    private:
        int                         _result;
        std::stack<char>            _operator;
        std::stack<int>             _operand;
    public:
        Parser(void);

        void                        feed(const std::string &expression);
        int                         operation(int nb1, int nb2, char op);
        int                         result(void) const;
        void                        reset(void);
};

#endif //                           __PARSER__