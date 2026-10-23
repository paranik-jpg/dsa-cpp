#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to divide two numbers
    without multiplication and division */
    int divide(int dividend, int divisor) {
        int sum = 0;
        int cnt = 0;
        while(sum+divisor<=dividend){
            cnt++;
            sum += divisor;
        }
        return cnt;
    }
};

int main() {
    int dividend = 10, divisor = 3;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to divide two numbers
    without multiplication and division */
    int ans = sol.divide(dividend, divisor);
    
    cout << "The result of dividing " << dividend << " and " << divisor << " is " << ans;
    
    return 0;
}