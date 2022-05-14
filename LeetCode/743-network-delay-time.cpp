///////////////////////////////////////////////////////////////////////////////////////////////
// classic dijkstra
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int N = n+10;
        int g[N][N];
        int dist[N];
        int st[N];
        memset(g, 0x3f, sizeof g); // we define infinite as 0x3f
        memset(dist, 0x3f, sizeof dist);
        memset(st, 0, sizeof st);
        
        for (int i=0 ; i<times.size() ; i++){
            int x=times[i][0], y=times[i][1], z=times[i][2];
            g[x][y] = min(g[x][y], z);
        }
        
        dist[k] = 0;
        for(int i=0 ; i<n ; i++){
            int t=-1;
            for(int j=1;j<n+1;j++){
                if (!st[j] && (t==-1||dist[t]>dist[j])){
                    t = j;
                }
            }
            st[t] = 1;
            for(int j=1;j<n+1;j++)
                dist[j] = min(dist[j], dist[t]+g[t][j]);
        }
        int res = 0;
        for(int j=1;j<n+1;j++){
            if (dist[j]==0x3f3f3f3f) return -1;
            res = max(res, dist[j]);
        }
        return res;
    }
};