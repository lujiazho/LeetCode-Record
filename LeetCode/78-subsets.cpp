///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int> nums, int i){
        if (i == nums.size()){
            res.push_back(cur);
            return;
        }
        dfs(nums, i+1); // not choose
        cur.push_back(nums[i]);
        dfs(nums, i+1); // choose
        cur.pop_back();
    }
};