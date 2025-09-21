#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n = 4;
    vector<vector<int>> ans = {{-1,5},{1,6},{3,5},{2,3}};
    int totalSum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int dist = abs(ans[i][0] - ans[j][0]) + abs(ans[i][1] - ans[j][1]);
            totalSum += dist;
        }
    }

    cout << "Total Manhattan distance: " << totalSum << endl; // Output: 22
    return 0;
}

