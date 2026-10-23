#include<bits/stdc++.h>
using namespace std;

int noOfEle(vector<vector<int>> matrix, int val){
    int cnt = 0;
    for(int i=0;i<matrix.size();i++){
        cnt += upper_bound(matrix[i].begin(),matrix[i].end(),val) - matrix[i].begin();
    }
    return cnt;
}

int findMedian(vector<vector<int>>&matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0;i<rows;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols-1]);
    }

    int req = rows*cols/2;

    while(low<=high){
        int mid = (low +high)/2;
        if (noOfEle(matrix, mid) <= req) low = mid+1;
        else high = mid-1;
    }

    return low;
}

int main(){
  vector<vector<int>> chu;
  chu =  {{1, 3, 8}, {2, 3, 4}, {1, 2, 5}};
  cout << findMedian(chu);
  return 0;
}

