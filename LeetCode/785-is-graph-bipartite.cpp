///////////////////////////////////////////////////////////////////////////////////////////////
// solve bipartite graph with colorizing method
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;
    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        for (int i=0 ; i<g.size() ; i++)
            color.push_back(0);
        for (int i=0 ; i<g.size() ; i++){
            if (!color[i])
                if (!dfs(i, 1))
                    return false;
        }
        return true;
    }
    bool dfs(int p, int c){
        color[p] = c;
        for (int i=0 ; i<g[p].size() ; i++){
            if (!color[g[p][i]]){
                if (!dfs(g[p][i], 3-c))
                    return false;
            }
            else if (color[g[p][i]] == c)
                return false;
        }
        return true;
    }
};