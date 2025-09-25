#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    // Compare each pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return nums[i]; // found duplicate
            }
        }
    }
    return -1; // should not happen
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums);  // Output: 2
    return 0;
}


  int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];          // move one step
            fast = nums[nums[fast]];    // move two steps
        } while (slow != fast);

        // Step 2: Find cycle entrance (duplicate number)
        slow = nums[0];                 // reset slow to start
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; 

int ans = -1;
// Already visited
for(int i = 0; i < nums.size(); i++){
    int index = abs(nums[i]);   // pick index from value
    
    if(nums[index] < 0){        // if already negative → duplicate
        ans = index;
        break;
    }
    // Visited mark
    nums[index] *= -1;          // mark as visited
}
return ans;