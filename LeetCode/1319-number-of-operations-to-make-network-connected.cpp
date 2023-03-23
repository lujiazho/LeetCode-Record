///////////////////////////////////////////////////////////////////////////////////////////////
// easy dfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len<n-1) return -1;

        vector<int> adj[n];
        for(auto v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                ans++;
            }
        }
        // find connected graph number and minus one
        return ans - 1;
    }
};