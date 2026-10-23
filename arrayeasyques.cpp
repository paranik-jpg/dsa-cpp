#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &a, long long k){
    int left = 0;
    int right = 0;
    int n = a.size();
    int maxLen = 0;
    long long sum = a[0];

    while(right<n){
        while(left<=right && sum>k){
            sum -= a[left];
            left++;
        }

        if (sum==k && (right-left+1 > maxLen)) maxLen = right-left+1;

        right++;
        if(right<n) sum += a[right];
    }

    return maxLen;
}

int main(){
    vector<int> tosort;
    tosort = {10, 5, 2, 7, 1, 9};
    int final = longestSubarrayWithSumK(tosort,15);
    cout << final;
    return 0;
}