#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find k maximum sum combinations
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> visited;

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans;

        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        pq.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        while(k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back(sum);

            if(i+1 <n1 && !visited.count({i+1, j})) {
                pq.push({nums1[i+1] + nums2[j], i+1, j});
                visited.insert({i+1, j});
            }

            if(j+1 <n2 && !visited.count({i, j+1})) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            }
        }

        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {7, 3, 50};
    vector<int> nums2 = {1, 6};
    int k = 3;
    vector<int> result = sol.maxCombinations(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}