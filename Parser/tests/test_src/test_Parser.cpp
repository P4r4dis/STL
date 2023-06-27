#include "../test_include/test_Parser.hpp"


Parser::Parser(void) :  _result(0)
{}

void                    Parser::feed(const std::string &s)                       
{                                                                                
    int             nb1;
    int             nb2;
    std::string tmp = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            tmp += s[i];
            if (s[i+1] < '0' || s[i+1] > '9')
            {
                _operand.push(std::stoi(tmp));
                tmp.erase();
            }
        }
        else if (s[i] != '(' && s[i] != ' ' && s[i] != ')')
            _operator.push(s[i]);
        else if (s[i] == ')')
        {
            nb1 = _operand.top();
            _operand.pop();
            nb2 = _operand.top();
            _operand.pop();
            _operand.push(operation(nb2, nb1, _operator.top()));
            _operator.pop();
        }
    }                             
    _result += _operand.top();                                                
}

int         Parser::operation(int nb1, int nb2, char op)
{
    switch (op)
    {
        case '+':
            return nb1 + nb2;
            break;
        case '-':
            return nb1 - nb2;
            break;
        case '*':
            return nb1 * nb2;
            break;
        case '/':
            return nb1 / nb2;
            break;
        case '%':
            return nb1 % nb2;
            break;
        default:
            return 0;
    }
}

int                         Parser::result(void) const
{
    return _result;
}

void                        Parser::reset(void)
{
    _result = 0;
}