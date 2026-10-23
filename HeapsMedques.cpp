#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using brute force
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<=k && i<n; i++) {
            pq.push(arr[i]);
        }

        for(int i=k+1; i<n; i++) {
            ans.push_back(pq.top());
            pq.pop();

            pq.push(arr[i]);
        }

        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

// Driver code
int main() {
    // Define the input array
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};

    // Define the value of k
    int k = 3;

    // Create object of Solution class
    Solution obj;

    // Call the function to sort the array
    vector<int> result = obj.sortNearlySortedArray(arr, k);

    // Print the sorted array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}