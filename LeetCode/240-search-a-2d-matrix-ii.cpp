///////////////////////////////////////////////////////////////////////////////////////////////
// easy to solve
////////////////
// Time Complexity: O(m*n)
// Space Complexity: O(m*n), dfs recersive function used stack
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=0;
        return dfs(matrix, i, j, target);
    }
    bool dfs(vector<vector<int>>& matrix, int i, int j, int target){
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] == INT_MAX || matrix[i][j] > target) return false;
        
        bool ret = false;
        if (j+1<matrix[0].size()) ret |= dfs(matrix, i, j+1, target);
        if (ret) return true;
        if (i+1<matrix.size()) ret |= dfs(matrix, i+1, j, target);
        if (ret) return true;
        matrix[i][j] = INT_MAX;
        return false;
    }
};