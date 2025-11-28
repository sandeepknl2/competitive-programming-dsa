#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1,0,0},{0,1,1},{1,1,1}};
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int width = 0, area = 0, maxa = 0;
    
    // Step 1: store heights for each column
    vector<int> height(cols, 0);

    // Step 2: go from bottom to top (as in your loop)
    for (int i = rows - 1; i >= 0; i--) {
        width = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1)
                height[j] = height[j] + 1; // add to existing vertical height
            else
                height[j] = 0; // reset if zero found
        }

        // compute area row-wise
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                width++;
                area = width * height[j];
                maxa = max(maxa, area);
            } else {
                width = 0;
            }
        }
    }

    cout << maxa;
}


optimized

