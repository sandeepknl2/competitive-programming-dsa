#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = mat.size();
    long long totalSum = 0;

    // Pick all possible top-left corners (i,j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Pick all possible bottom-right corners (p,q)
            for (int p = i; p < n; p++) {
                for (int q = j; q < n; q++) {
                    
                    // Sum elements inside this submatrix
                    long long subSum = 0;
                    for (int x = i; x <= p; x++) {
                        for (int y = j; y <= q; y++) {
                            subSum += mat[x][y];
                        }
                    }
                    
                    totalSum += subSum; // Add to answer
                }
            }
        }
    }

    cout << "Sum of all submatrices = " << totalSum << endl;
    return 0;
}


optimized

// C++ program to find the sum of all possible submatrices
#include <iostream>
#include <vector>
using namespace std;

// Function to find the sum of all submatrices 
int matrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int res = 0;
    
    // Iterate through each element in the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Number of ways to choose the top-left corner 
            int topLeft = (i + 1) * (j + 1);
            
            // Number of ways to choose the bottom-right corner
            int bottomRight = (n - i) * (n - j);
            
            // Calculate contribution of current element
            res += (topLeft * bottomRight * matrix[i][j]);
        }
    }
    
    return res;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1},
        {1, 1}
    };
    
    cout << matrixSum(matrix);
    return 0;
}