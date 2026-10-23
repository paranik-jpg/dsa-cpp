#include<bits/stdc++.h>
using namespace std;

int GCD(int n1,int n2) {
        while (n1> 0 && n2> 0){
            if (n2 > n1) n2 = n2 % n1;
            else n1 = n1 % n2;
        }
        if (n2==0) return n1;
        return n2;
    }

int main(){
    cout << GCD(4,9);
    return 0;
}