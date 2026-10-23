#include<bits/stdc++.h>
using namespace std;

int main () {
    map<int, int> mappy;
    for(int i=1;i<=5;i++){
        mappy[i] = i*i;
    }
    /*for(auto it : mappy){
        cout << it.first << " " << it.second << endl;
    }
    cout << mappy[8];*/
    auto it = mappy.upper_bound(3);
    cout << it->second;
    return 0;
}