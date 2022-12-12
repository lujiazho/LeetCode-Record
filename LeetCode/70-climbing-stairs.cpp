///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (dp[n] != 0) return dp[n];
        int res = climbStairs(n-1) + climbStairs(n-2);
        dp[n] = res;
        return res;
    }
};