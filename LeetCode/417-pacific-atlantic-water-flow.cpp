///////////////////////////////////////////////////////////////////////////////////////////////
// tricky because it has plat place
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int m, n;
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> res;
    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        if(!size(mat)) return res;
        
        m = size(mat), n = size(mat[0]);
        
        // record if each node can get to atlantic or pacific
        atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));

        // start from left and right side
        for(int i = 0; i < m; i++) {
            dfs(mat, pacific, i, 0);
            dfs(mat, atlantic, i, n - 1);
        }
        // start from up and down side
        for(int i = 0; i < n; i++) {
            dfs(mat, pacific, 0, i);
            dfs(mat, atlantic, m - 1, i);
        }
        return res;
    }
    void dfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, int i, int j){        
        if(visited[i][j]) return;
        
        visited[i][j] = true;
        
        if(atlantic[i][j] && pacific[i][j]) 
            res.push_back(vector<int>{i, j});

        // walk to higher place
        if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); // down
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j); // up
        if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); // right
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1); // left
    }
};