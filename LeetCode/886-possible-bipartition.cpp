///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(max(m, n)), m is edge num
// Space Complexity: O(m)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> dislike_map(n, vector<int>{});
        for (auto pair:dislikes) {
            int a=pair[0]-1, b=pair[1]-1;
            dislike_map[a].push_back(b);
            dislike_map[b].push_back(a);
        }

        vector<int> color(n, 0); // 1 and 2
        for (int i=0 ; i<n ; i++) {
            if (!color[i]) {
                if (!dfs(color, dislike_map, i, 1)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<int> &color, vector<vector<int>> &dislike_map, int idx, int c) {
        color[idx] = c;
        bool res = true;
        for (auto nex:dislike_map[idx]) {
            if (color[nex] == 0) {
                res &= dfs(color, dislike_map, nex, 3-c);
            } else if (color[nex] == c) {
                return false;
            }
        }
        return res;
    }
};