int n = 10;
vector<int> res(n, 0);
vector<vector<int>> arr = {{1,5,3}, {4,8,7}, {6,9,1}};

for(int i = 0; i < arr.size(); i++){
    int a = arr[i][0];
    int b = arr[i][1];
    int k = arr[i][2];

    for(int j = a-1; j <= b-1; j++){
        res[j] += k; // accumulate values
    }
}

// Print result
for(int i = 0; i < n; i++){
    cout << res[i] << " ";
}
44

#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);  // difference array, size n+2 to handle b+1
    long maxValue = 0;
    long current = 0;

    // Apply each query in O(1) using difference array
    for (auto q : queries) {
        int a = q[0];  // start index (1-indexed)
        int b = q[1];  // end index (inclusive)
        int k = q[2];  // value to add

        arr[a] += k;
        arr[b + 1] -= k;
    }

    // Compute prefix sum to get actual values and find max
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        if (current > maxValue)
            maxValue = current;
    }

    return maxValue;
}

int main() {
    int n = 10;
    vector<vector<int>> queries = {{1,5,3}, {4,8,7}, {6,9,1}};

    cout << arrayManipulation(n, queries) << endl;  // Output: 10

    return 0;
}
