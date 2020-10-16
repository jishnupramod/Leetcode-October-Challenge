/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size()-1, row = 0;
        int left = 0, right = matrix.size() ? matrix[0].size()-1 : -1;
        if (right < left) return false;
        while (top <= bottom) {
            int mid = top + (bottom-top) / 2;
            if (matrix[mid][0] <= target and matrix[mid].back() >= target) {
                row = mid;
                break;
            } else if (matrix[mid].back() < target)
                top = mid + 1;
            else
                bottom = mid - 1;
        }
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

