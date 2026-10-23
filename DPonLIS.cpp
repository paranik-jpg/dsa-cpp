#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the length of the longest bitonic sequence
    int LongestBitonicSequence(vector<int>& arr) {
        int n = arr.size();

          vector<int> dp1(n, 1);
          for(int ind = 0; ind < n; ind++) {
              for(int prevInd = 0; prevInd < ind; prevInd++) {
                  if(arr[prevInd] < arr[ind] && 1 + dp1[prevInd] > dp1[ind] ) {
                      dp1[ind] = 1 + dp1[prevInd];
                  }
              }
          }

          int ans = -1;
          vector<int> dp2(n, 1);
          for(int ind = n - 1; ind >= 0; ind--) {
              for(int prevInd = n - 1; prevInd > ind; prevInd--) {
                  if(arr[prevInd] < arr[ind] && 1 + dp2[prevInd] > dp2[ind] ) {
                      dp2[ind] = 1 + dp2[prevInd];
                  }
              }
              ans = max(ans, dp1[ind] + dp2[ind] - 1);
          }

          return ans;
    }
};


int main() {
    vector<int> arr = {5, 1, 4, 2, 3, 6, 8, 7};

    // Creating an object of Solution class
    Solution sol;

    // Function call to get the length of longest bitonic sequence
    int lengthOfLongestBitonicSequence = sol.LongestBitonicSequence(arr);

    //  Output
    cout << "The length of the Longest Bitonic Sequence is: " << lengthOfLongestBitonicSequence << endl;

    return 0;
}
