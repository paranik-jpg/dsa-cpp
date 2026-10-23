#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int first = -1;
    int last = -1;
    // finding first
    while(low<=high){
        int mid = (low + high) / 2;
        if(nums[mid]==target){
            first = mid;
            high = mid - 1;
        } else if (target>nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    
    low = 0;
    high = n-1;
    // finding last
    while(low<=high){
        int mid = (low + high) / 2;
        if(nums[mid]==target){
            last = mid;
            low = mid + 1;
        } else if (target>nums[mid]) low = mid + 1;
        else high = mid - 1;
    }

    return {first, last};
}

int main(){
    vector<int> arr1;
    int target = 5;
    vector<int> ans;
    arr1 = {5, 7, 7, 8, 8, 10};
    ans = searchRange(arr1, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}