///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(k*m*n)
// Space Complexity: O(m)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        while (k){
            vector<int> v;
            for (int i=0 ; i<m ; i++)
                v.push_back(grid[i][n-1]);
            for (int i=0 ; i<m ; i++){
                for (int j=n-1 ; j>0 ; j--){
                    grid[i][j] = grid[i][j-1];
                }
            }
            grid[0][0] = v[v.size()-1];
            for (int i=1 ; i<m ; i++)
                grid[i][0] = v[i-1];
            k--;
        }
        return grid;
    }
};