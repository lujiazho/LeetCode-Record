///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i=0 ; i<grid.size() ; i++){
            for (int j=0 ; j<grid[0].size() ; j++){
                if (grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        for (auto dir:dirs){
            int d0=dir[0], d1=dir[1];
            if (i+d0 < grid.size() && j+d1 < grid[0].size() && grid[i+d0][j+d1] == '1')
                dfs(grid, i+d0, j+d1);
        }
    }
};