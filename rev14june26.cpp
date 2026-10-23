#include <bits/stdc++.h>
using namespace std;

void printPattern22(int n) {
    int lim = 2*n-1;
    int cenLoc = n-1;

    for(int i=0; i<lim; i++) {
        for(int j=0; j<lim; j++) {
            int val = max(abs(i-cenLoc), abs(j-cenLoc)) + 1;
            cout << val << " ";
        }
        cout << endl;
    }
}

void printPattern21(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (i==0 || j==0 || i==n-1 || j==n-1) {
                cout << "*" << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void printPattern20(int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<=i; j++) {
            cout << "*" << " ";
        }
        for(int j=0; j<2*(n-i-1); j++) {
            cout << "  ";
        }
        for(int j=0; j<=i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    for(int i=0; i<2*n; i++) {
        cout << "*" << " ";
    }
    cout << endl;

    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            cout << "*" << " ";
        }
        for(int j=0; j<2*(n-i-1); j++) {
            cout << "  ";
        }
        for(int j=0; j<=i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

int main() {
    // int n;
    // cout << "Enter a number : ";
    // cin >> n;
    printPattern20(5);
    return 0;
}