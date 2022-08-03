///////////////////////////////////////////////////////////////////////////////////////////////
// easy dp thinking
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums); // dp[i]: maximum sum of array ending at i
        int res = dp[0];
        for(int i = 1; i < size(nums); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]); 
            res = max(res, dp[i]);
        }
        return res;
    }
};