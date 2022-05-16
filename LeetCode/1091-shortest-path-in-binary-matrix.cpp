///////////////////////////////////////////////////////////////////////////////////////////////
// a little bothering bfs
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        
        vector<vector<int>> v;
        unordered_set<string> visited;
        v.push_back(vector<int>{0,0,1});
        visited.insert("0_0");
        
        int dx[] = {-1,-1,-1,0,1,1,1,0};
        int dy[] = {-1,0,1,1,1,0,-1,-1};
        
        while (v.size()){
            vector<vector<int>> v_new;
            for (int i=0 ; i<v.size() ; i++){
                int x=v[i][0], y=v[i][1], d = v[i][2];
                if (x == n-1 && y == n-1) return d;
                for (int j=0 ; j<8 ; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx>=0 && nx<n && ny>=0 && ny<n && visited.find(to_string(nx)+"_"+to_string(ny)) == visited.end() && !grid[nx][ny]){
                        v_new.push_back(vector<int>{nx,ny,d+1});
                        visited.insert(to_string(nx)+"_"+to_string(ny));
                    }
                }
            }
            v = v_new;
        }
        return -1;
    }
};
