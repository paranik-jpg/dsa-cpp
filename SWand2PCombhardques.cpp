#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int nS = s.size();
        int tS = t.size();
        
        int minLen = nS + 1;
        string ans = "";  

        for(int i=0;i<nS;i++){
            map<char,int> mpp;
            for(char c:t){
                mpp[c]++;
            }
            int cnt = 0;
            for(int j=i;j<nS;j++){
                mpp[s[j]]--;
                if(mpp[s[j]]>=0){
                    cnt++;
                }
                if(cnt==tS){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        ans = s.substr(i,minLen);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    string s = "a";
    string t = "aa";
    Solution sol;
    string ans = sol.minWindow(s,t);
    cout << ans << endl;
    return 0;
}