#include <bits/stdc++.h>
using namespace std;

// Solution class to compute minimum cost to cut a stick
class Solution {
private:
    int solve(int i, int j, vector<int>& cuts){
        if(i > j) {
          return 0;
        }

        int mini = INT_MAX;
        for(int k = i; k <= j; k++) {
          int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) +
                     solve(k + 1, j, cuts);
          mini = min(mini, cost);
        }

        return mini;
    }

public:
    // Function to calculate minimum total cost to cut the stick
 int minimumCost(int n, int c, vector<int>& cuts) {
    cuts.push_back(n);
   cuts.insert(cuts.begin(), 0);
   sort(cuts.begin(), cuts.end());
   return solve(1, c, cuts);
    }
};

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    Solution sol;
    cout << "The minimum cost incurred is: " << sol.minimumCost(n, c, cuts) << endl;

    return 0;
}
