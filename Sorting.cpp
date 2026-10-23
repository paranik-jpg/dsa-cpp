#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        map<int,int> hashy;
        for(int i=0;i<nums.size();i++){
            hashy[nums[i]]++;
        }
        nums.clear();
        for(auto it : hashy){
            nums.push_back(it.first);
        }
        return hashy.size();
    }

int main(){
    vector<int> tosort;
    tosort = {0, 0, 3, 3, 5, 6};
    removeDuplicates(tosort);
    for(auto it=tosort.begin();it!=tosort.end();it++){
        cout << *(it) << endl;
    }
    return 0;
}