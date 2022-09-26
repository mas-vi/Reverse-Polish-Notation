#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int val_operator(char operat)
{
    switch (operat)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
        break;
    }
}

bool comp(char left, char right)
{
    return val_operator(left) >= val_operator(right);
}




void parse(std::string& input)
{
    std::string aux{};
    std::vector<char> oper{};
    for (int i{}; i < input.size(); i++)
    {
        aux.erase();
        while (!is_operator(input[i]) && i < input.size()  && input[i] != ' ')
            aux += input[i++];
        if (!aux.empty())
            std::cout << aux << ' ';
        if (is_operator(input[i]))
        {
            if (oper.empty())
                oper.push_back(input[i]);
            else
            {
                if (comp(oper.back(), input[i]))
                {
                    std::cout << oper.back() << ' ';
                    oper.pop_back();
                    oper.push_back(input[i]);
                }
                else
                {
                    oper.push_back(input[i]);
                }
            }
        }
    }
    while (!oper.empty())
    {
        std::cout << oper.back() << ' ';
        oper.pop_back();

    }

    
}

int main()
{
    std::ifstream in("input.txt");
    std::string input{};
    std::getline(in,input);
    parse(input);
    





    in.close();


}

