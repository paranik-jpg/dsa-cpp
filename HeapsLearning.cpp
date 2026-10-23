#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the given array is a min-heap
    bool isMinHeap(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++) {
            if(nums[(i-1)/2]>nums[i]) return false;
        }
        return true;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 25, 15};

    // Output result
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
}
