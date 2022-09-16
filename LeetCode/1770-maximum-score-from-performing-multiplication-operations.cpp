///////////////////////////////////////////////////////////////////////////////////////////////
// classic memorization, but this gives TLE
////////////////
// Time Complexity: O(2^n), should be less than this
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dp[1001][1001] = {};
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return dfs(nums, multipliers, 0, 0);
    }
    int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size()) return 0;
        
        if (!dp[l][i]) {
            int r = nums.size() - 1 - (i - l);
            int front = nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1);
            int end = nums[r] * mults[i] + dfs(nums, mults, l, i + 1);
            
            dp[l][i] = max(front, end);
        }
        
        return dp[l][i];
    }
};