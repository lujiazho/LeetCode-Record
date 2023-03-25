///////////////////////////////////////////////////////////////////////////////////////////////
// easy dfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(vector<int>adj[],int src,vector<bool>&vis,int &counter){
        if(vis[src]) return;
        vis[src] = true;
        counter ++;
        for(auto ele : adj[src]){
            if(!vis[ele]) dfs(adj, ele, vis, counter);
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        vector<int> temp;
        for(int i=0 ; i<n ; i++) {
            if(!vis[i]){
                int counter = 0;
                dfs(adj, i, vis, counter);
                temp.push_back(counter);
            }
        }
        long long res = 0;
        long total = 0;
        for(int i=0 ; i<temp.size() ; i++) {
            res += (long)temp[i]*total;
            total += temp[i];
        }
        return res;
    }
};