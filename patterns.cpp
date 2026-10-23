#include<bits/stdc++.h>
using namespace std;

void patternPrinter(int n){
    for(int i=0;i<=2*n-2;i++){
       for(int j=0;j<=2*n-2;j++){
        int top = i;
        int left = j;
        int bottom = 2*n-2-i;
        int right = 2*n-2-j;
        cout << n - min (min(top, bottom),min (left, right)) << " ";
       }
       cout << endl;
    }
}
int main(){
    int no;
    cin >> no;
    patternPrinter(no);
    return 0;
}