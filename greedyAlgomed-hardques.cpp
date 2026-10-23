#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of candies 
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> leftNeigh(n);
        leftNeigh[0] = 1;

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                leftNeigh[i] = leftNeigh[i-1]+1;
            } else {
                leftNeigh[i] = 1;
            }
        }

        int sum = 0;
        sum += max(1,leftNeigh[n-1]);
        int curr = 1;
        int right = 1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) {
                curr = right + 1;
                right = curr;
            } else {
                curr = 1;
            }
            sum += max(leftNeigh[i], curr);
        }

        return sum;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> ratings = {1, 0, 5};
    cout << "Minimum candies required: " << obj.candy(ratings) << endl;
    return 0;
}
