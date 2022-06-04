///////////////////////////////////////////////////////////////////////////////////////////////
// not easy, but we can exchange space for time
////////////////
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> res;
    vector<string> grid;
    int N = 20;
    int nn;
    vector<int> col, dg, udg; // column, diagonal, back-diagonal
    vector<vector<string>> solveNQueens(int n) {
        string ini = "";
        nn = n;
        for (int i=0 ; i<n ; i++) ini += '.';
        for (int i=0 ; i<n ; i++) grid.push_back(ini);
        for (int i=0 ; i<N ; i++) {
            col.push_back(0);
            dg.push_back(0);
            udg.push_back(0);
        }
        dfs(0);
        return res;
    }
    void dfs(int u){
        if (u == nn){
            res.push_back(grid);
            return;
        }
        for (int i=0 ; i<nn ; i++){
            if (!col[i] && !dg[u+i] && !udg[nn-i+u-1]){
                grid[u][i] = 'Q';
                col[i] = dg[u+i] = udg[nn - i + u - 1] = 1;
                dfs(u+1);
                col[i] = dg[u+i] = udg[nn - i + u - 1] = 0;
                grid[u][i] = '.';
            }
        }
    }
};