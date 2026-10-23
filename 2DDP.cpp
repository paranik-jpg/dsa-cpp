#include <bits/stdc++.h>
using namespace std;

// Class to solve the problem
class Solution {
public:
    // Function to start the process
    int minimumPathSum(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for(int i = n - 2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0];
    }
};

// Main function
int main() {
    Solution obj;
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    cout << obj.minimumPathSum(triangle);
    return 0;
}
