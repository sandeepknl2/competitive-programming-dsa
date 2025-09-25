#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {2, 3, 0, -1};
    int n = arr.size();
    int maa = INT_MIN;

    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = i; j < n; j++) {
            prod *= arr[j];
            maa = max(maa, prod);
        }
    }
    cout << maa;
    return 0;
}


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++) {
        // prefix product (left to right)
        prefix *= nums[i];
        // suffix product (right to left)
        suffix *= nums[n - 1 - i];

        ans = max(ans, max(prefix, suffix));

        // reset if product becomes 0
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 0, -1};
    cout << maxProduct(arr);
    return 0;
}
