#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {4, -1, 2, 1, -5};
    int n = arr.size(), k = 5;
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum >= k)
                minLen = min(minLen, j - i + 1);
        }
    }

    cout << (minLen == INT_MAX ? -1 : minLen);
}


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int minLength = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};