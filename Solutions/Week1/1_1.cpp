#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int isBalanced(std::string text)
{
    if (text.length() == 1)
    {
        return 1;
    }

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket brack(next, position);
        std::string possible = "()[]{}";

        if (possible.find(next) == std::string::npos)
        {
            continue;
        }

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(brack);// Add opening bracket to stack
        }

        else
        {           
            Bracket brack_top = opening_brackets_stack.top(); 
            opening_brackets_stack.pop(); // remove top bracket from stack 
            if (!brack_top.Matchc(next)) // check if removed bracket and current bracket close
            {
                return position + 1;
            }
        }
    }
    return 0;
}