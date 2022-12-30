///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        if(n == 0) return res;

        vector<int> path; // current path
        dfs(graph, res, path, 0, n - 1);

        return res;
    }
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {
        path.push_back(src);
        if(src == dst) {
            result.push_back(path);
            return;
        }
        // because path is not referenced, we don't have to pop back
        for(auto node : graph[src]) dfs(graph, result, path, node, dst);
    }
};