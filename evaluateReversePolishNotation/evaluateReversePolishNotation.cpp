/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

int evaluate(const vector<string>& reversePolish)
{
    stack<int> s;

    for (int i = 0; i < reversePolish.size(); ++i)
    {
        string current = reversePolish[i];
        if (current == "+" || current == "-" || current == "*" || current == "/")
        {
            if (s.size() < 2)
            {
                // ToDo: Error handling
                break;
            }
            else
            {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                if (current == "+")
                {
                    s.push(v1 + v2);
                }
                else if (current == "-")
                {
                    s.push(v2 - v1);
                }
                else if (current == "*")
                {
                    s.push(v1 * v2);
                }
                else
                {
                    s.push(v2 / v1);
                }
            }
        }
        else
        {
            s.push(atoi(current.c_str()));
        }
    }

    return s.top();
}

int main(int argc, char ** argv)
{
    vector<string> reversePolish;
    reversePolish.push_back("4");
    reversePolish.push_back("13");
    reversePolish.push_back("5");
    reversePolish.push_back("/");
    reversePolish.push_back("+");

    cout << evaluate(reversePolish) << endl;

    return 0;
}
