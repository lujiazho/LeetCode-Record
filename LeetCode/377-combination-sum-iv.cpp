///////////////////////////////////////////////////////////////////////////////////////////////
// very tricky if we shift two loops in reduced array case
////////////////
// Time Complexity: O(n*target)
// Space Complexity: O(target)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i][j]: choose from top i, exactly add to j, nums of combinations
        vector<uint> dp(target+1, 0);
        dp[0] = 1;
        
        for (int j=1 ; j<=target ; j++){
            for (int i=1 ; i<nums.size()+1 ; i++){
                if (nums[i-1] <= j)
                    dp[j] += dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};