#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to be called from driver code
    bool wildcardMatching(string &S1, string &S2) {
        int n = S1.size();
        int m = S2.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for(int j = 1; j <= m; j++) {
            prev[j] = false;
        }

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int it = i; it > 0; it--) {
                if(S1[it - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for(int j = 1; j <= m; j++) {

                if(S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                    curr[j] = prev[j - 1];
                }

                else if(S1[i - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }

                else  {
                    curr[j] = false;
                }

            }
            prev = curr;
        }

        return prev[m];
    }
};

// Driver Code
int main() {
    // Example pattern and text
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Create a Solution object
    Solution obj;

    // Call the matching function and display the result
    if (obj.wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}
