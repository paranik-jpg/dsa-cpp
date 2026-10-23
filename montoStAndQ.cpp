#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n,n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
            }
        if(st.empty()){
            nse[i] = n;
            }else{
                nse[i] = st.top();
            }
        st.push(i);
    }
    return nse;
}

vector<int> previousSmallerEqualElements(vector<int>& nums) {
    int n = nums.size();
        vector<int> psee(n,-1);
        stack<int> st;

        for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()]>nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    psee[i] = -1;
                }else{
                    psee[i] = st.top();
                }
                st.push(i);
        }
        return psee;
    }

// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(vector<int> arr, int n) {
    vector<int> nse = nextSmallerElements(arr);
    vector<int> psse = previousSmallerEqualElements(arr);
    int maxi = 0;

    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]*(nse[i]-psse[i]-1));
    }

    return maxi;
}

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};  // Histogram bar heights
    int n = 7;  // Size of the histogram

    // Call the function and print the result
    cout << "The largest area in the histogram is " << largestarea(arr, n) << endl;
    return 0;
}
