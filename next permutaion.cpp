BRURTE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to generate next permutation manually (naive swap)
bool naiveNextPermutation(vector<int>& nums) {
    int n = nums.size();
    // Try all possible swaps to create next lexicographic permutation
    for (int i = n-2; i >=0; i--) {
        for (int j = n-1; j > i; j--) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
                sort(nums.begin() + i + 1, nums.end()); // smallest order for suffix
                return true; // found next permutation
            }
        }
    }
    // If no next permutation exists, return false
    sort(nums.begin(), nums.end()); // wrap around to smallest
    return false;
}

int main() {
    vector<int> nums = {1,1,5};

    naiveNextPermutation(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    return 0;
}


optimal leetocde
int i = nums.size() - 1;
while (i > 0 && nums[i-1] >= nums[i]) {
    i--;
}

if (i == 0) {
    reverse(nums.begin(), nums.end());
    return;
}

int j = nums.size() - 1;
while (j >= i && nums[j] <= nums[i-1]) {
    j--;
}

swap(nums[i-1], nums[j]);
reverse(nums.begin() + i, nums.end());
