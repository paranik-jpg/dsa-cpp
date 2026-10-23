#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int LIS(vector<int>& arr) {
          int n = arr.size();

          vector<int> dp(n, 1);
          vector<int> hash(n);

          int ans = 0;
          int last_ind = 0;
          for(int ind = 0; ind < n; ind++) {
            hash[ind] = ind;
              for(int prevInd = 0; prevInd < ind; prevInd++) {
                  if(arr[prevInd] < arr[ind] && 1 + dp[prevInd] > dp[ind] ) {
                      dp[ind] = 1 + dp[prevInd];
                      hash[ind] = prevInd;
                  }
              }

              if(dp[ind] > ans) {
                ans = dp[ind];
                last_ind = ind;
              }
          }

          vector<int> lis;
          lis.push_back(arr[last_ind]);

          while(hash[last_ind] != last_ind) {
            last_ind = hash[last_ind];
            lis.push_back(arr[last_ind]);
          }

          reverse(lis.begin(), lis.end());
          for(auto it : lis) {
            cout << it << " ";
          }

          cout << endl;

          return ans;
      }
  };


int main() {
    vector<int> nums = {5, 4, 11, 1, 16,};

    // Creating an object of Solution class
    Solution sol;
    int lengthOfLIS = sol.LIS(nums);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
