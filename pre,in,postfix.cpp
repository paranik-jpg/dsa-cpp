#include <bits/stdc++.h>
using namespace std;

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> st;
    int i = 0;
    int n = postfix.size();

    while(i<n){
        if ((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z') || (postfix[i]>='0' && postfix[i]<='9')){
            string temp(1,postfix[i]);
            st.push(temp);
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string strr = '(' + t2 + postfix[i] + t1 + ')';
            st.push(strr);
        }
        i++;
    }

    return(st.top());
}

int main() {
    string postfix = "AB-DE+F*/";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
