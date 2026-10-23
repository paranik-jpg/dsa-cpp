#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    int n;
    cin >> n;
    // vector<int> dp(n+1, -1);
    // cout << fib(n, dp) << endl;

    int prev2 = 0;
    int prev = 1;

    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    cout << prev << endl;

    return 0;
}