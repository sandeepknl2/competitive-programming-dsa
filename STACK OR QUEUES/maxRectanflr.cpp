#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> mat = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int n = mat.size();
    int m = mat[0].size();
    int rectan = 0;

    // Step 1: try each cell as top-left corner
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '1') {

                int minWidth = INT_MAX; // track the smallest width

                // Step 2: expand downward row by row
                for (int k = i; k < n && mat[k][j] == '1'; k++) {

                    // Step 3: count consecutive '1's in row k from column j
                    int width = 0;
                    for (int t = j; t < m && mat[k][t] == '1'; t++)
                        width++;

                    // Step 4: update min width so far
                    minWidth = min(minWidth, width);

                    // Step 5: compute height and area
                    int height = k - i + 1;
                    int area = minWidth * height;
                    rectan = max(rectan, area);
                }
            }
        }
    }

    cout << "Maximum rectangle area = " << rectan << endl;
}


optimized

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int maxArea = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            stack<int> stk;
            for (int i = 0; i < heights.size(); i++) {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                stk.push(i);
            }
        }
        return maxArea;
    }
};
