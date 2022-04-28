///////////////////////////////////////////////////////////////////////////////////////////////
// bfs
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int r,c;
    int minimumEffortPath(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0,0});
        
        // up right down left
        int dirs[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        while (pq.size()){
            auto cur = pq.top();
            pq.pop();
            
            int last_diff = cur[0];
            int cur_effort = cur[1];
            int x = cur[2];
            int y = cur[3];
            
            if(x==r-1 && y==c-1)
                return cur_effort;
            if(heights[x][y]==-1)continue; // there might be repetition of same point
            for(int i=0 ; i<4 ; i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx<0 || ny<0 || nx>=r || ny>=c || heights[nx][ny]==-1)
                    continue;
                int diff = abs(heights[nx][ny] - heights[x][y]);
                pq.push({diff , max(cur_effort, diff) , nx , ny});
            }
            heights[x][y] = -1;
        }
        return -1;
    }
};