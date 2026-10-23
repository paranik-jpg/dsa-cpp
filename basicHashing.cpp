#include<bits/stdc++.h>
using namespace std;

int mostFrequentElement(vector<int>& nums) {
        map<int,int> mapu;
        for(int num: nums){
            mapu[num]++;
        }
        int maxnum;
        int maxcount = 0;
        for(pair<int,int> sui: mapu){
            if(sui.second > maxcount){
                maxcount = sui.second;
                maxnum = sui.first;
            } else if(sui.second == maxcount && sui.first < maxnum) maxnum = sui.first;
        }
        return maxnum;
    }

int main(){
    vector<int> li;
    li = {4, 4, 5, 5, 6};
    int maxxie;
    maxxie = mostFrequentElement(li);
    cout << maxxie;
    return 0;
}