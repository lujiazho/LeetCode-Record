///////////////////////////////////////////////////////////////////////////////////////////////
// not easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> child[100001];
    int res = 1;
    int longestPath(vector<int>& parent, string s){
        // save children for dfs convenience
        for(int i=1 ; i<parent.size() ; i++) child[parent[i]].push_back(i);

        dfs(s,0);
        return res;
    }
    int dfs(string &s, int curr_node)
    {
        // if leaf node, return 1
        if(child[curr_node].empty()) return 1;

        int mx1 = 0, mx2 = 0;
        for(auto &child_node : child[curr_node])
        {
            // get longest length from child node to any it's children (one-sided)
            // this must be done before below continue, because the answer may not through root 0
            int len = dfs(s, child_node);
            // if equal, then skip
            if(s[curr_node] == s[child_node]) continue;

            // record the longest two length
            if(len > mx1) {
                mx2 = mx1;
                mx1 = len;
            } else mx2 = max(mx2, len);
        }

        // Update the result.
        res = max(res, 1 + mx1 + mx2);
        // return longest path length
        return mx1 + 1;
    }
};