///////////////////////////////////////////////////////////////////////////////////////////////
// easy dfs, and i learned how to accumulate 2d vector
////////////////
// Time Complexity: O(m*n)
// Space Complexity: O(m*n), worst case
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 2d vector accumulate
        int sum = accumulate(grid.cbegin(), 
                             grid.cend(), 
                             0, 
                             [](auto lhs, const auto& rhs) {
                                 return accumulate(rhs.cbegin(), rhs.cend(), lhs);
                             });
        if (sum == 0) return 0;
        int res = 0;
        for (int i=0 ; i<grid.size() ; i++){
            for (int j=0 ; j<grid[0].size() ; j++){
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        int res = 1;
        grid[i][j] = 0;
        if (j+1 < grid[0].size() && grid[i][j+1] == 1)
            res += dfs(grid, i, j+1);
        if (i+1 < grid.size() && grid[i+1][j] == 1)
            res += dfs(grid, i+1, j);
        if (j-1 >= 0 && grid[i][j-1] == 1)
            res += dfs(grid, i, j-1);
        if (i-1 >= 0 && grid[i-1][j] == 1)
            res += dfs(grid, i-1, j);
        return res;
    }
};