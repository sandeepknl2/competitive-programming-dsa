// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int> arr={1,6,1};
    int k=3;
    int n=arr.size();
    
    vector<int> dist;
    int dif=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dif=abs(arr[i]-arr[j]);
            dist.push_back(dif);
        }
    }
    int s=dist.size();
    for(int i=0;i<s;i++){
        if(i==k-1)
        cout<<dist[i];
    }
    // Write C++ code here
   

    return 0;
}

opyimzed
 BS

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function: count pairs with distance <= mid
    int countPairs(vector<int>& nums, int mid) {
        int n = nums.size();
        int count = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1; // pairs (i, i+1..j-1)
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 1: sort array
        int n = nums.size();
        int left = 0;                    // min distance
        int right = nums[n - 1] - nums[0]; // max distance

        // Step 2: binary search on distance
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = countPairs(nums, mid);

            if (cnt >= k) {
                right = mid;  // search smaller distances
            } else {
                left = mid + 1; // search larger distances
            }
        }
        return left;
    }
};
