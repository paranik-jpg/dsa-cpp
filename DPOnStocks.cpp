#include <bits/stdc++.h>
using namespace std;

int stockProfit(vector<int>& Arr) {
  int n = Arr.size();
  vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                dp[ind][buy] = max(-Arr[ind] + dp[ind + 1][0],
               dp[ind + 1][1]);
            } else {
                dp[ind][buy] = max(Arr[ind] + dp[ind + 2][1], dp[ind + 1][0]);
            }
        }
    }

  return dp[0][1];
}

int main() {
  vector<int> prices{4, 9, 0, 4, 10};

  cout << "The maximum profit that can be generated is " << stockProfit(prices)
       << endl;
  return 0;
}
