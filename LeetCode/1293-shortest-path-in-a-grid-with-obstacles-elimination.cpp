///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, a tricky thing is we need to go on exploring this path even though it already been
// walked if we now have more k available
////////////////
// Time Complexity: O(m*n*k)
// Space Complexity: O(m*n*k)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // This vector stores the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<vector<int>> q;
        q.push({0,0,0,k}); // x, y, currentStep, remaining k
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            // current location
            int x = t[0], y = t[1];
            // out of edge
            if(x<0 || x>=m || y<0 || y>=n) continue;
            // it's the end
            if(x == m-1 && y == n-1) return t[2];
            
            // obstackle
            if(grid[x][y] == 1){
                if(t[3] > 0) t[3]--; // have enough k
                else continue; // no more k, this path is not goable
            }
            
            // walked, and with more available k, we stop exploring current path
            // walked, but with less available k, we'd like to explore this path
            if(visited[x][y]!=-1 && visited[x][y] >= t[3]) continue;
            visited[x][y] = t[3];
                
            q.push({x+1, y, t[2]+1, t[3]});
            q.push({x-1, y, t[2]+1, t[3]});
            q.push({x, y+1, t[2]+1, t[3]});
            q.push({x, y-1, t[2]+1, t[3]});
        }
        
        return -1;
    }
};