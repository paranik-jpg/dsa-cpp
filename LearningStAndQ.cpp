#include <bits/stdc++.h>
using namespace std;

// Class to implement Minimum Stack
class MinStack {
public:
    stack<pair<int,int>> st;
   
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        if(st.empty()) st.push({value,value});
        else st.push({value,min(value,st.top().second)}); 
    }
    
    // Method to pop a value from stack
    void pop() {
        st.pop();
    }
    
    // Method to get the top of stack
    int top() {
        return(st.top().first);
    }
    
    // Method to get the minimum in stack
    int getMin() {
        return(st.top().second);
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}