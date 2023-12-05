#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int postfixeval(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-int('0'));
        }
        else{
            int operand1 = st.top();
            // cout<<"Operand1: "<<operand1<<endl;
            st.pop();
            int operand2 = st.top();
            // cout<<"Opearnd2: "<<operand2<<endl;
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand2-operand1);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '/':
                st.push(operand2/operand1);
                break;
            case '^':
                st.push(pow(operand2,operand1));
                break;
            }
        }
    }
    return st.top();
}
int main(){
    cout<<"Postfix evaluation for expression is: "<<postfixeval("42*4+7*2/")<<endl;
}