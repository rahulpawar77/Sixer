#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string exp;
    stack<char> s;
    bool valid = true;

    cout << "==========  STUDENT NAME = SANGRAM WAMAN  ==========" << endl;
    cout << "========         ROLL NO = 266       ========" << endl;

    cout << "Enter expression: ";
    getline(cin, exp);

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty())
            {
                valid = false;
                break;
            }

            char top = s.top();
            s.pop();

            if ((exp[i] == ')' && top != '(') ||
                (exp[i] == '}' && top != '{') ||
                (exp[i] == ']' && top != '['))
            {
                valid = false;
                break;
            }
        }
    }

    if (!s.empty())
    {
        valid = false;
    }

    if (valid)
    {
        cout << "Expression is Well Parenthesized." << endl;
    }
    else
    {
        cout << "Expression is Not Well Parenthesized." << endl;
    }

    return 0;
}
