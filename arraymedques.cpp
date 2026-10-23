#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            preSum += nums[i];
            int rem = k - preSum;
            count += mpp[rem];
            mpp[preSum]++;
        }
        return count;
    }

int main(){
    vector<vector<int>> tosort;
    tosort = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(tosort);
    int n = tosort.size();
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << tosort[i][j] << " ";
            }
            cout << endl;
        }
    return 0;
}