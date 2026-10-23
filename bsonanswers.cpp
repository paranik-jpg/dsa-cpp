#include<bits/stdc++.h>
using namespace std;

int noOfGasStationsNow(vector<int> &arr, long double dist){
    int n = arr.size();
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        int curr = (arr[i+1] - arr[i]) / dist;
        if(curr*dist == arr[i+1] - arr[i]) curr--;
        cnt += curr;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for(int i=0;i<n-1;i++){
        long double curr = arr[i+1] - arr[i];
        high = max(high, curr);
    }
    
    while(high - low > 1e-6){
        long double mid = (low + high) / 2.0;
        int cnt = noOfGasStationsNow(arr, mid);

        if(cnt > k) low = mid;
        else high = mid;
    }

    return high;
}

int main(){
  vector<int> chu;
  chu =  {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
  cout << minimiseMaxDistance(chu,9);
  return 0;
}

