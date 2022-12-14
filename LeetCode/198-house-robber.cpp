///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rob(vector<int>& nums) {
        const int size = nums.size();
        // dp[i]: maximum value that end up with ith house (must rob ith)
        int dp[105] = {0};
        dp[0] = nums[0];
        if (size == 1) return dp[0];
        dp[1] = max(nums[0], nums[1]);
        if (size == 2) return dp[1];
        dp[2] = nums[0]+nums[2];
        if (size == 3) return max(dp[1], dp[2]);
        for (int i=3 ; i<size ; i++) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        return max(dp[size-1], dp[size-2]);
    }
};