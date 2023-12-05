//Infix to Prefix 
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
string infixtoprefix(string s)
{
    cout<<"Original expression is: "<<s<<endl;
    string s1;
    for(int i=s.length();i>=0;i--){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
        s1+=s[i];
    }
    cout<<"Reversed expression is: "<<s1<<endl;
    stack<char> stck;
    string postexp;
    for (int i = 0; i < (s1.length()); i++)
    {
        if (s1[i] == '(')
        {
            stck.push(s1[i]);
        }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
        {
            postexp += s1[i];
        }
        else if (s1[i] == ')')
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
            while (!stck.empty() && prec(s1[i]) <= prec(stck.top()))
            {
                postexp += stck.top();
                stck.pop();
            }
            stck.push(s1[i]);
        }
    }
    while (!stck.empty())
    {
        postexp += stck.top();
        stck.pop();
    }
    string prefix;
    for(int i=postexp.length();i>=0;i--){
        prefix+=postexp[i];
    }
    return prefix;

}
int main()
{
    cout << "infix to prefix expression is: " << infixtoprefix("(a-b/c)*(a/k-l)") << endl;
    return 0;

}
