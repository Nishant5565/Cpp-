//Infix to Postfix
#include <iostream>
#include <stack>
using namespace std;
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtopostfix(string s)
{
    stack<char> stck;
    string postexp;
    for (int i = 0; i < (s.length()); i++)
    {
        if (s[i] == '(')
        {
            stck.push(s[i]);
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            postexp += s[i];
        }
        else if (s[i] == ')')
        {
            while (!stck.empty() && stck.top() != '(')
            {
                postexp += stck.top();
                stck.pop();
            }
            if (!stck.empty())
            {
                stck.pop();
            }
        }
        else
        {
            while (!stck.empty() && prec(s[i]) <= prec(stck.top()))
            {
                postexp += stck.top();
                stck.pop();
            }
            stck.push(s[i]);
        }
    }
    while (!stck.empty())
    {
        postexp += stck.top();
        stck.pop();
    }
    return postexp;
}
int main()
{
    cout << "infix to postfix expression is: " << infixtopostfix("(a-b/c)*(a/k-l)") << endl;
    return 0;

}
