#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2};
    int n = arr.size();

    vector<vector<int>> subs;

    // pick all possible i, j, k that are distinct
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && i != k) {  // all indices must be different
                    subs.push_back({arr[i], arr[j], arr[k]});
                }
            }
        }
    }

    // remove duplicates (since array has repeated numbers)
    set<vector<int>> uniqueSubs(subs.begin(), subs.end());

    // print all unique permutations
    for (auto v : uniqueSubs) {
        for (int x : v)
            cout << x;
        cout << " ";
    }
}


recursion optimized
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& res) {
    if (current.size() == nums.size()) {
        res.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Skip if this element is already used
        if (used[i]) continue;
        // Skip duplicates: if the number is same as previous and previous was not used
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, res);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> res;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    backtrack(nums, used, current, res);
    return res;
}