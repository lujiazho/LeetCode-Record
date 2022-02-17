///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, just traverse all cases
////////////////
// Time Complexity: O(target^(candidates.length)), this is worst & impossible case
// Space Complexity: O(target*(target^candidates.length)), worst as well
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    int t,n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t = target;
        n = candidates.size();
        dfs(0, 0, candidates);
        return res;
    }
    void dfs(int idx, int val, vector<int>& candidates){
        if (val == t){
            res.push_back(v);
            return;
        }
        if (idx == n) return;
        int num = 0;
        dfs(idx+1, val, candidates);
        while (1){
            if (val + candidates[idx] <= t){
                v.push_back(candidates[idx]);
                val += candidates[idx];
                dfs(idx+1, val, candidates);
                num += 1;
            }else break;
        }
        while (num){
            v.pop_back();
            val -= candidates[idx];
            num -= 1;
        }
    }
};