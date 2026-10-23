#include<bits/stdc++.h>
using namespace std;

int main(){
    int A[] = {1,4,5,5,9,9,9,22};
    int ind = upper_bound(A, A + 5,5) - A;
    cout << A[ind];
    cout << endl;
    cout << ind;
    return 0;
}