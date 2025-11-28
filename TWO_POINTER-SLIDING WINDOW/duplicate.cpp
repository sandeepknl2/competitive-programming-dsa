#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,3,4,2,2};
    int n = arr.size();
   sort(arr.begin(),arr.end());
   
   bool istrue=true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && istrue == true) {
                cout << arr[j];
                istrue = false;
                break;
            }
        }
        if (!istrue) break; // stop outer loop too
    }
}


optimized  using make cisited as -1

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int ind = abs(nums[i]);
            if (nums[ind] < 0) {
                return ind;
            }
            nums[ind] = -nums[ind];
        }
        return -1;
    }
};