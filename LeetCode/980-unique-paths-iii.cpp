///////////////////////////////////////////////////////////////////////////////////////////////
// brute force
////////////////
// Time Complexity: O(3^20), because m*n <= 20
// Space Complexity: O(m*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    int m, n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    // check valid location
    bool isvalid(int i, int j)
    {
        return i >= 0 and j >= 0 and i < m and j < n;
    }
    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>> &grid)
    {
        // if all is walked and here is destination, count it
        if (left == -1 and pair<int, int>(i, j) == dest) return 1;
        // visited
        grid[i][j] = -1;

        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (isvalid(x, y) and grid[x][y] != -1) ans += dfs(x, y, left - 1, dest, grid);
        }
        // Backtrack
        grid[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        pair<int, int> src, dest;
        int empty = 0; // number of can-be-walked cells

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) empty++;
                if (grid[i][j] == 1) src = {i, j};
                if (grid[i][j] == 2) dest = {i, j};
            }
        }
        return dfs(src.first, src.second, empty, dest, grid);
    }
};