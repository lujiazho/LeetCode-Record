///////////////////////////////////////////////////////////////////////////////////////////////
// classic dp
////////////////
// Time Complexity: O(n*target*k)
// Space Complexity: O(n*target)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        // dp[i][j]: num of possible ways to add to j when using i dice
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for (int i=1 ; i<k+1 ; i++) {
            if (i > target) break;
            dp[1][i] = 1;
        }

        for (int i=2 ; i<n+1 ; i++) {
            for (int j=1 ; j<target+1 ; j++) {
                for (int l=1 ; l<k+1 ; l++) {
                    if (j-l < 0) break;
                    dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
                }
            }
        }
        return (dp[n][target]) % MOD;
    }
};