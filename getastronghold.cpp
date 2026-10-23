#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int temp) {
    if (s.empty()) {
        s.push(temp);
        return;
    }
    
    int val = s.top();
    s.pop();
    insert(s, temp);
    
    s.push(val);
}

// Function to reverse the stack
void reverseStack(stack<int> &st) {
    if (!st.empty()) {
        int temp = st.top();
        st.pop();
        
        reverseStack(st);
        
        insert(st, temp);
    }
}

int main() {
    // Create a sample stack
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    // Reverse the stack
    reverseStack(st);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}