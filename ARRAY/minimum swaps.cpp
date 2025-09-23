#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 9, 5, 8, 7, 4};
    int n = arr.size();
    int k = 6;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) // already good element
            continue;
        else {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] <= k) {
                    swap(arr[i], arr[j]); // swap once
                    cnt++;
                    break; // stop after one swap
                }
            }
        }
    }

    cout << cnt << endl; // expected output = 2
    return 0;
}


opyimized

 int n = arr.size();

    // Step 1: count how many numbers are <= k
    int good = 0;
    for (int x : arr) {
        if (x <= k) good++;
    }

    // if no good elements or all are good → no swaps needed
    if (good == 0 || good == n) return 0;

    // Step 2: count bad elements in the first window of size good
    int bad = 0;
    for (int i = 0; i < good; i++) {
        if (arr[i] > k) bad++;
    }

    int ans = bad;

    // Step 3: slide the window
    for (int i = 0, j = good; j < n; i++, j++) {
        if (arr[i] > k) bad--;   // remove left element if bad
        if (arr[j] > k) bad++;   // add right element if bad
        ans = min(ans, bad);     // track minimum bads
    }

    return ans;
}