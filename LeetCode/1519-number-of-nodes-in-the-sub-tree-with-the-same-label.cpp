///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj, string &labels, int i, vector<int> &result){
        // default value: count self; and this is also used for checking walked path
        result[i] = 1;

        // for storing the number of label in current subtree
        vector<int> ans(26, 0);
        ans[labels[i] - 'a'] = 1;

        for(int j = 0; j != adj[i].size(); j++) {
            // if it's not walked
            if(!result[adj[i][j]]){
                vector<int> tmp = dfs(adj, labels, adj[i][j], result);
                for(int k = 0; k != 26; k++) ans[k] += tmp[k];
            }
        }

        // update result
        result[i] = ans[labels[i] - 'a'];

        return ans;
    }
  
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // build graph
        vector<vector<int>> adj(n);
        for(int i = 0; i != edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> res(n,0);

        dfs(adj, labels, 0, res);
        return res;
    }
};