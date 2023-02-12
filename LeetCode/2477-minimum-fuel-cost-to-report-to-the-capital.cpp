///////////////////////////////////////////////////////////////////////////////////////////////
// dfs, from bottom to top
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long ans = 0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1);

        for (const vector<int>& road : roads) {
            const int u = road[0];
            const int v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(graph, 0, -1, seats);
        return ans;
    }

    int dfs(const vector<vector<int>>& graph, int u, int prev, int seats) {
        int people = 1;
        for (const int v : graph[u]) {
            if (v == prev) continue;
            people += dfs(graph, v, u, seats);
        }
        if (u > 0) ans += people / seats + (people % seats ? 1 : 0);
        return people;
    }
};