#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the single 
    number in the given array */
    vector<int> singleNumber(vector<int>& nums){
        long xorr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) xorr ^= nums[i];

        int rightmost = (xorr & (xorr-1))^xorr;
        int b1=0;
        int b2=0;

        for(int i=0;i<n;i++){
            if(nums[i]&rightmost) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1,b2};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3,5,7, 5, 2};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    number in the given array */
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}