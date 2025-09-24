class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int r = 0, c = n - 1;           // start top-right
        while (r < m && c >= 0) {
            int val = matrix[r][c];
            if (val == target) return true;
            if (val > target) c--;     // eliminate this column
            else r++;                  // eliminate this row
        }
        return false;
    }
};
