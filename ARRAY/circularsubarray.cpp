#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {5, -2, 3, 4};
    int n = arr.size();

    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
        int currSum = 0;

        // Part 1: sum from start to end of array
        for (int i = start; i < n; i++) {
            currSum += arr[i];
            maxSum = max(maxSum, currSum);
        }

        // Part 2: sum from beginning to just before start (for wrap-around)
        currSum = 0;
        for (int i = 0; i < start; i++) {
            currSum += arr[i];
            maxSum = max(maxSum, currSum + arr[start]); // add first element if needed
        }
    }

    cout << "Max Circular Subarray Sum = " << maxSum << endl;
    return 0;
}

with modulus

class Solution {
public:
    int maxCircularSum(vector<int> &arr, int n) {
        int maxSum = INT_MIN;

        // Try every starting index
        for (int start = 0; start < n; start++) {
            int currSum = 0;

            // Extend subarray length up to n (circular)
            for (int len = 0; len < n; len++) {
                int idx = (start + len) % n; // circular wrap
                currSum += arr[idx];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};


optimized

#include <iostream>
#include <vector>
using namespace std;

int maxCircularSum(vector<int> &arr) {

    int totalSum = 0;
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        // Kadane's to find maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        // Kadane's to find minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        // Sum of all the elements of input array
        totalSum = totalSum + arr[i];
    }

    int normalSum = maxSum;
    int circularSum = totalSum - minSum;

    // If the minimum subarray is equal to total Sum
    // then we just need to return normalSum
    if (minSum == totalSum)
        return normalSum;

    return max(normalSum, circularSum);
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << maxCircularSum(arr);
}
