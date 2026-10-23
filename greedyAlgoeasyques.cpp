#include<bits/stdc++.h>
using namespace std;

// Struct to represent an item with value and weight
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    bool static comp(Item i1, Item i2){
        if((double)((double)i1.value/(double)i1.weight) >= (double)((double)i2.value/(double)i2.weight)) return true;
        return false;
    }

    // Function to calculate the maximum value we can get with fractional knapsack
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr,arr+n,comp);
        int currW = 0;
        double totVal = 0.0;
        for(int i=0;i<n;i++){
            if(currW + arr[i].weight <= W){
                currW += arr[i].weight;
                totVal += (double)arr[i].value;
            } else {
                totVal += (double)((double)arr[i].value/(double)arr[i].weight)*(W-currW);
                break;
            }
        }
        return totVal;
    }
};

int main() {
    int n = 4, weight = 90;  // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = { {100,20},{60,10},{100,50}, {200,50} };
    Solution obj;

    // Calculate the maximum value we can get with the fractional knapsack
    double ans = obj.fractionalKnapsack(weight, arr, n);
    
    // Output the result
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    
    return 0;
}