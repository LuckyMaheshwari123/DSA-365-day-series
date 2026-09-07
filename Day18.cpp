#include<bits/stdc++.h>
using namespace std;
    
    
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Intuition:
        // We want to rotate the matrix 90 degrees clockwise.
        // Instead of moving elements directly in the original matrix,
        // we create a new matrix to store the rotated result.
        //
        // For every element matrix[i][j]:
        // - Its row index becomes its column index.
        // - Its column index becomes m - 1 - i.
        //
        // Therefore, the element at (i, j) moves to:
        // (j, m - 1 - i)
        //
        // Example:
        // matrix[0][0] = 1
        // It moves to m2[0][2].
        //
        // matrix[0][1] = 2
        // It moves to m2[1][2].
        //
        // After placing every element, we copy the rotated
        // matrix back into the original matrix.

        vector<vector<int>> m2(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                m2[j][m - 1 - i] = matrix[i][j];
            }
        }

        matrix = m2;
    }
// Time Complexity: O(n²) — We visit every element once.
// Space Complexity: O(n²) — We create an extra matrix to store the rotated result.

// optimal approach
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Transpose the matrix
        // j = i + 1 because:
        // j = i -> diagonal element, do not swap
        // j < i -> already swapped
        // j > i -> need to swap

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse the elements of each row
        // This completes the 90-degree clockwise rotation.

        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};