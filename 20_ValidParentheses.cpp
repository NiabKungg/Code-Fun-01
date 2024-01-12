#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> myStack;
    for (int i = 0; i < s.size(); i++)
    {
        if (myStack.empty() and (s[i] == ')' or s[i] == '}' or s[i] == ']'))
        {
            return false;
        }
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            myStack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (myStack.top() == '(')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (myStack.top() == '[')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (myStack.top() == '{')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (myStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    cout << isValid("[(((())))]}");
    return 0;
}
