///////////////////////////////////////////////////////////////////////////////////////////////
// this implementation is good
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> adjList; // for quick finding neighbor
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n); // open space
        for(vector<int> &e:edges) {
            // undirected
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        // dfs directly return the answer
        return dfs(-1, 0, adjList, hasApple);
    }
    int dfs(int prev, int curr, vector<vector<int>>& a, vector<bool>& hasApple) {
        int ans = 0;
        for (auto x : a[curr]) {
            if (x != prev) {
                int res = dfs(curr, x, a, hasApple);
                if (res > 0 || hasApple[x]) ans += (res + 2);
            }
        }
        return ans;
    }
};