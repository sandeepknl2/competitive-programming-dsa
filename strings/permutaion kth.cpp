#include <iostream>
using namespace std;

int main() {
    int n = 3; // change as needed

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k) {
                    cout << i << j << k << endl;
                }
            }
        }
    }

    return 0;
}

opyimizwd
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& arr) {
    for (int x : arr) cout << x;
    cout << endl;
}

bool nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;
    
    // 1. Find pivot
    while (i >= 0 && arr[i] >= arr[i+1]) i--;
    if (i < 0) return false; // last permutation reached

    // 2. Find element to swap with
    int j = n - 1;
    while (arr[j] <= arr[i]) j--;

    swap(arr[i], arr[j]);

    // 3. Reverse suffix
    int l = i+1, r = n-1;
    while (l < r) swap(arr[l++], arr[r--]);

    return true;
}

int main() {
    int n = 3;
    vector<int> arr;
    for (int i=1; i<=n; i++) arr.push_back(i);

    printVector(arr); // first permutation
    while (nextPermutation(arr)) {
        printVector(arr);
    }
    return 0;
}


optimkized

    vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    vector<int> fact(n, 1);
    for (int i = 1; i < n; i++) fact[i] = fact[i-1] * i;

    k--; // convert to 0-indexed
    string result = "";

    for (int i = n; i >= 1; i--) {
        int idx = k / fact[i-1];
        result += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[i-1];
    }
    return result;
}