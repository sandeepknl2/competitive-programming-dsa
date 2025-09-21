#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        bool duplicate = false;
        // check if nums[i] occurs at another index
        for(int j = 0; j < n; j++) {
            if(i != j && nums[i] == nums[j]) {
                duplicate = true;
                break;
            }
        }
        if(!duplicate) { // found the unique element
            cout << nums[i] << endl;
            break;
        }
    }

    return 0;
}


optimize bs
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while(low < high){
        int mid = (low + high) / 2;
        if(mid % 2 == 1) mid--; // make mid even
        if(nums[mid] == nums[mid+1])
            low = mid + 2;  // go right
        else
            high = mid;     // go left
    }
    return nums[low];
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl; // Output: 2
    return 0;
}


else
XPOR

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    int ans = 0;
    for (int num : nums) {
        ans ^= num;   // XOR with each element
    }

    cout << "Single element = " << ans << endl;
    return 0;
}
