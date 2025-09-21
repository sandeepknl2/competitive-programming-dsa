normal

#include <iostream>
#include <vector>
#include <algorithm> // for min
using namespace std;

int main() {
    vector<int> nums = {2, 2, 3, 4, 0, 1, 2};

    int start = 0, end = nums.size() - 1; // 0, 6
    int mimi = nums[0];                   // initial guess = 2

    cout << "Initial array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Always update mimi with nums[mid]
        mimi = min(mimi, nums[mid]);

        // Print current state
        cout << "start=" << start << " end=" << end << " mid=" << mid 
             << " nums[mid]=" << nums[mid] << " mimi=" << mimi << endl;

        // Case 1: duplicates, can’t decide
        if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
            cout << "Case: duplicates at start, mid, end → shrink both sides\n";
            start++; 
            end--;
        }
        // Case 2: left half sorted
        else if (nums[start] <= nums[mid]) {
            cout << "Case: left half sorted → move right\n";
            mimi = min(mimi, nums[start]);
            start = mid + 1;
        }
        // Case 3: right half sorted
        else {
            cout << "Case: right half sorted → move left\n";
            mimi = min(mimi, nums[mid]);
            end = mid - 1;
        }

        cout << "Updated mimi=" << mimi << "\n\n";
    }

    cout << "Final Minimum = " << mimi << endl;
    return 0;
}

}



better think like find out the sorting in which position then remove the duuplicates

int findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end]) {
            start = mid + 1;   // min must be in right half
        } else if (nums[mid] < nums[end]) {
            end = mid;         // min in left including mid
        } else {
            end--;             // duplicates: shrink search space
        }
    }
    return nums[start];
}
