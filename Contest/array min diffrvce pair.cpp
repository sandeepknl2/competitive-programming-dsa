#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    vector<int> result;
    int n = arr.size();
    if(n < 2) return result;

    sort(arr.begin(), arr.end());  // sort array

    int minDiff = INT_MAX;

    // Step 1: find minimum difference between adjacent elements
    for(int i = 0; i < n - 1; i++) {
        minDiff = min(minDiff, arr[i+1] - arr[i]);
    }

    // Step 2: collect all pairs with that difference
    for(int i = 0; i < n - 1; i++) {
        if(arr[i+1] - arr[i] == minDiff) {
            result.push_back(arr[i]);
            result.push_back(arr[i+1]);
        }
    }

    return result;
}
