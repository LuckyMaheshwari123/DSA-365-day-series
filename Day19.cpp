#include<bits/stdc++.h>
using namespace std;
// The intuition is to traverse the matrix layer by layer, like peeling an onion.

// Maintain four boundaries: top, bottom, left, and right.

// For each layer, traverse the top row from left to right, the right column from top to bottom, the bottom row from right to left, and the left column from bottom to top.

// After each traversal, shrink the corresponding boundary. Repeat until the boundaries cross.

// The `if` conditions prevent duplicate traversal when the remaining matrix has only one row or one column.


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int m=matrix.size();
         int n= matrix[0].size();
         vector<int>ans;
         int top=0;
         int left=0;
         int bottom=m-1;
         int right=n-1;
        
        while(left<=right && top<=bottom){
            //iterate from left to right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
        
         // iterate from top down by making right constat
         for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
         }
          right--;
         if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
             bottom--;
         }
         if(left<=right){
             for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
             }
             left++;
         }
    }
         return ans;
    
    }
    
