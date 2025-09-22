#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> seen;      // track numbers seen
    unordered_set<int> duplicates; // store duplicates

    for (int x : nums) {
        if (!seen.insert(x).second) { 
            // insert returns {iterator, bool}, bool=false if already exists
            duplicates.insert(x);
        }
    }

    // convert set to vector
    return vector<int>(duplicates.begin(), duplicates.end());
}

int main() {
    vector<int> arr = {2, 3, 1, 2, 3};
    vector<int> duplicates = findDuplicates(arr);

    for (int x : duplicates) cout << x << " ";
    return 0;
}


optimixwd indexing

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            res.push_back(abs(nums[i]));
        } else {
            nums[index] = -nums[index]; // mark visited
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, 1, 2, 3};
    vector<int> duplicates = findDuplicates(arr);

    for (int x : duplicates) cout << x << " ";
    return 0;
}
