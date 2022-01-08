///////////////////////////////////////////////////////////////////////////////////////////////
// nearly brute force, but with hashmap to reduce redundant calculation
////////////////
// Time Complexity: O(9^row)
// Space Complexity: O(row*col1*col2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int R;
    int C;
    vector<vector<int>> g;
    map<pair<int, pair<int,int>>, int> m;
    int cherryPickup(vector<vector<int>>& grid) {
        g = grid;
        R = grid.size();
        C = grid[0].size();
        return dfs(0, 0, C-1);
    }
    int dfs(int row, int col1, int col2){
        if (row >= R){
            return 0;
        }
        auto get = m.find(pair<int, pair<int,int>>(row, pair<int,int>(col1,col2)));
        if (get != m.end())
            return m[pair<int, pair<int,int>>(row, pair<int,int>(col1,col2))];
        int ret = g[row][col1] + g[row][col2];
        if (col1 == col2){
            ret /= 2;
        }
        int max_ = 0;
        for (int i=col1-1 ; i <= col1+1 ; i++){
            for (int j=col2-1 ; j <= col2+1 ; j++){
                if (i >= 0 && j >= 0 && i < C && j < C){
                    max_ = max(max_, dfs(row+1, i, j));
                }
            }
        }
        m.insert(pair<pair<int, pair<int,int>>, int>(pair<int, pair<int,int>>(row,pair<int,int>(col1,col2)), ret+max_));
        return ret + max_;
    }
};