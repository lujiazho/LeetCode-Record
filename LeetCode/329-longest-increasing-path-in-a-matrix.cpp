///////////////////////////////////////////////////////////////////////////////////////////////
// bad idea
////////////////
// Time Complexity: O(mn*mn)
// Space Complexity: O(mn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int m,n;
    vector<vector<int>> mat;
    unordered_map<string,int> map;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        mat = matrix;
        
        int res = 0;
        for (int i=0 ; i<m ; i++){
            for (int j=0 ; j<n ; j++){
                res = max(res, dfs(i,j));
            }
        }
        return res;
    }
    int dfs(int x, int y){
        if (map.find(to_string(x)+"_"+to_string(y)) != map.end())
            return map[to_string(x)+"_"+to_string(y)];
        int ret = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i=0 ; i<4 ; i++){
            int nx=dx[i]+x, ny=dy[i]+y;
            if (nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny] > mat[x][y])
                ret = max(ret, dfs(nx,ny)+1);
        }
        map[to_string(x)+"_"+to_string(y)] = ret;
        return ret;
    }
};