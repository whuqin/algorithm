/***************************************************************************
 * 
 * Copyright (c) 2014. All Rights Reserved
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6 
 **************************************************************************/
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int evalRPN(vector<string> &tokens) {
    stack<int> digits;
    string operators("+-*/");
    vector<string>::iterator it = tokens.begin();
    int a = 0;
    int b = 0;
    for (; it != tokens.end(); ++it)
    {
        if (string::npos != operators.find(*it))
        {
            if (digits.size() < 2)
            {
                return 0;
            }
            a = digits.top();
            digits.pop();
            b = digits.top();
            digits.pop();
            if (*it == "+") 
            {
                digits.push(b+a);
            } 
            else if (*it == "-")
            {
                digits.push(b-a);
            } 
            else if (*it == "*")
            {
                digits.push(b*a);
            }
            else // (*it == "/")
            {
                if (a == 0)
                {
                    return 0;
                }
                digits.push(b/a);
            }
        }
        else
        {
            a = atoi(it->c_str());
            if (a == 0 && (*it != "0"))
            {
                return 0;
            }
            digits.push(a);
        }
    }
    return digits.top();
}
 

int main()
{
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("1");
    vec.push_back("+");
    vec.push_back("3");
    vec.push_back("*");
    cout << evalRPN(vec) << endl;

}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
