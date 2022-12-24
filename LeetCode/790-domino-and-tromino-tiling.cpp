///////////////////////////////////////////////////////////////////////////////////////////////
// hard, hard to understand as well
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        long long mod = 1e9+7;
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        dp[0] = {1, 1};
        dp[1] = {2, 2};

        for (int i=2 ; i<n ; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-2][1]*2) % mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % mod;
        }
        return dp[n-1][0] % mod;
    }
};