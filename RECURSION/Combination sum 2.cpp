#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 7;
    int k = 3; // number of elements in combination
    vector<vector<int>> res; // store triplets together

    // Generate all combinations of 3 numbers (i < j < l)
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int l = j + 1; l <= n; l++) {
                if (i + j + l == n) {
                    res.push_back({i, j, l});
                }
            }
        }
    }

    // Print results
    for (auto &triplet : res) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}


optimize

class Solution {
public:
  vector<vector<int>> res;
    vector<int> path;
    
    void backtrack(int k, int n, int start) {
        // Base case: k numbers chosen
        if (path.size() == k) {
            int sum = 0;
            for (int x : path) sum += x;
            if (sum == n) res.push_back(path);
            return;
        }

        // Try all numbers from 'start' to 9 (LeetCode constraint)
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(k, n, i + 1); // pick next number
            path.pop_back();        // backtrack
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
               backtrack(k, n, 1);
        return res;
    
    }
};