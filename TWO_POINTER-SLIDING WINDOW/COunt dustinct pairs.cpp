#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int TotalPairs(vector<int> nums, int k) {
        int n = nums.size();
        int count = 0;

        // brute-force loop
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(abs(nums[i] - nums[j]) == k){
                    // make sure pair is unique
                    bool duplicate = false;
                    for(int x = 0; x < i; x++){
                        for(int y = x + 1; y < j; y++){
                            if((nums[x] == nums[i] && nums[y] == nums[j]) ||
                               (nums[x] == nums[j] && nums[y] == nums[i])){
                                duplicate = true;
                                break;
                            }
                        }
                        if(duplicate) break;
                    }
                    if(!duplicate) count++;
                }
            }
        }

        return count;
    }
};


two pinter'


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int TotalPairs(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());  // O(n log n)
        int n = nums.size();
        int i = 0, j = 1;  // two pointers
        int count = 0;

        while(j < n) {
            int diff = nums[j] - nums[i];

            if(diff < k) j++;           // need bigger difference
            else if(diff > k) i++;      // need smaller difference
            else {                      // diff == k
                count++;
                int val_i = nums[i], val_j = nums[j];

                // skip duplicates for nums[i]
                while(i < n && nums[i] == val_i) i++;
                // skip duplicates for nums[j]
                while(j < n && nums[j] == val_j) j++;
            }

            if(i == j) j++;  // make sure j > i
        }

        return count;
    }
};



optimized class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
         if(k == 0){
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;
        int count = 0;
        for(auto [num,f] : freq){
            if(f > 1) count++;  // only numbers with duplicates
        }
        return count;
    }

    unordered_set<int> s(nums.begin(), nums.end());
    int count = 0;
    for(int num : s){
        if(s.count(num + k)) count++;  // count each pair once
    }
    return count;
        
    }
};