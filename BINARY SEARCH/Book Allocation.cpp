#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive helper to divide books among students
int allocateBooks(vector<int>& arr, int n, int k, int idx) {
    // If only one student left → they take all remaining books
    if (k == 1) {
        int sum = 0;
        for (int i = idx; i < n; i++) sum += arr[i];
        return sum;
    }

    // If not enough books for students → impossible
    if (n - idx < k) return INT_MAX;

    int sum = 0;
    int best = INT_MAX;

    // Try giving books from idx..i to current student
    for (int i = idx; i <= n - k; i++) {
        sum += arr[i];  // add one book to current student
        int next = allocateBooks(arr, n, k - 1, i + 1);
        if (next != INT_MAX) {
            int worst = max(sum, next);    // max load among all students
            best = min(best, worst);       // minimize the worst
        }
    }

    return best;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;  
    int n = arr.size();

    if (k > n) {
        cout << -1 << endl;  // not enough books
    } else {
        cout << "Minimum Maximum Partition Sum = " 
             << allocateBooks(arr, n, k, 0) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            int students = 1;
            long long currSum = 0;
            bool possible = true;

            for (int pages : arr) {
                if (currSum + pages <= mid) {
                    currSum += pages;
                } else {
                    students++;
                    currSum = pages;
                    if (students > k) {
                        possible = false;
                        break;
                    }
                }
            }

            if (possible) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    Solution s;
    cout << s.findPages(arr, k) << endl; // Output: 113
}
