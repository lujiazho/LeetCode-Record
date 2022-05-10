///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(2^9)
// Space Complexity: O(2^9)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> v;
    int N;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        N = n;
        dfs(k, 1);
        return res;
    }
    void dfs(int times, int cur){
        if (!times){
            int num = 0;
            for (int i=0 ; i<v.size() ; i++)
                num += v[i];
            if (num == N)
                res.push_back(v);
            return;
        }
        if (cur > 9) return;
        // not use
        dfs(times, cur+1);
        // use
        v.push_back(cur);
        dfs(times-1, cur+1);
        v.pop_back();
    }
};