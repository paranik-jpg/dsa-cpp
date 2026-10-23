#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Finds the longest valid section by checking every possible range.
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0, max_len = 0;
        map<int, int> mpp;

        while (r < n) {
          mpp[fruits[r]]++;

		  if (mpp.size() > 2) {
			while (mpp.size() > 2) {
            	mpp[fruits[l]]--;
				if(mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
		  }

         max_len = max(max_len, r - l + 1);
         r++;
        }

        return max_len;
    }
};

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};

    Solution solution;

    cout << solution.totalFruit(fruits) << endl;

    return 0;
}
