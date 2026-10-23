#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {

        vector<int> prev(W + 1, 0);
        for(int w = wt[0]; w <= W; w++) {
            prev[w] = (w/wt[0])*val[0];
        }

        for(int ind = 1; ind < n; ind++) {
            vector<int> curr(W + 1, 0);
            for(int w = 0; w <= W; w++) {
                int notTake = 0 + prev[w];
                int take = INT_MIN;
                if(w >= wt[ind]) {
                    take = val[ind] + curr[w - wt[ind]];
                }

                curr[w] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }
};

// Driver code
int main() {
    // Initialize item weights
    vector<int> wt = {2, 4, 6};

    // Initialize item values
    vector<int> val = {5, 11, 13};

    // Weight capacity of the knapsack
    int W = 10;

    // Number of items
    int n = wt.size();

    // Create Solution object
    Solution obj;

    // Output the result
    cout << "The Maximum value of items the thief can steal is "
         << obj.unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}
