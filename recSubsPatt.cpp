#include <bits/stdc++.h>
using namespace std;

int printAllSub(int idx, int currSum, int n, vector<int>& arr, int sum) {
    if(idx == n) {
        if(currSum == sum) {
            return 1;
        }
        return 0;
    }

    currSum += arr[idx];
    int left = printAllSub(idx + 1, currSum, n, arr, sum);
    currSum -= arr[idx];

    int right = printAllSub(idx + 1, currSum, n, arr, sum);

    return left + right;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int n = 3;

    int sum = 2;

    cout << printAllSub(0, 0, n, arr, sum);
    return 0;
}