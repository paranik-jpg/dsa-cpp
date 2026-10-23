#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to be called externally
    int maximumNonAdjacentSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);

        dp[0] = arr[0];

        for(int i = 1; i < n; i++) {
            int take = arr[i];

            if(i > 1) {
                take += dp[i - 2];
            }

            int nonTake = dp[i - 1];

            dp[i] = max(take, nonTake);
        }

        return dp[n - 1];
    }
};

int main() {
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;

    // Output the result
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}