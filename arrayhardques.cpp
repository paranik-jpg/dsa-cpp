#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size();
        int xory = 0;
        for(int i=0;i<n;i++){
            xory ^= nums[i];
            xory ^= (i+1);
        } 

        int bitNo = 0;
        while(1){
            if((xory & (1<<bitNo)) != 0) break;
            bitNo ++;
        }

        int zero = 0;
        int one = 0;

        for(int i=0;i<n;i++){
            if((nums[i] & (1<<bitNo)) != 0) one ^= nums[i];
            else zero ^= nums[i];
        }

        for(int i=1;i<=n;i++){
            if((i & (1<<bitNo)) != 0) one ^= i;
            else zero ^= i;
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==zero) cnt++;
        }

        if(cnt==2) return{zero,one}; 
        return{one,zero}; 
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
