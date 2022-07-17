///////////////////////////////////////////////////////////////////////////////////////////////
// it's hard, explain:
// if put n-th number at the last position, we have dp[n-1][k] methods to get k inverse pairs
// if put n-th number at the second last position, we have dp[n-1][k-1] methods to get k inverse
//      because n-th number (in second last pos) must be larger than the number in the last pos
// if put ... at the third last position, we have dp[n-1][k-2] methods to get k inverse, because
//      n-th number (in third last pos) must be larger than the two number after it.
// ...
// Now we get dp[n][k] = dp[n-1][k] + dp[n-1][k-1] + ... + dp[n-1][k-n+1] (k-n+1 should be >= 0)
// in order to get rid of using loop to get this sum, we can see that we have this:
//      dp[n][k-1] = dp[n-1][k-1] + dp[n-1][k-2] + ... + dp[n-1][k-n+1] + dp[n-1][k-n]
// Now dp[n][k] - dp[n][k-1] = dp[n-1][k] - dp[n-1][k-n]
// Therefore, dp[n][k] = dp[n-1][k] + dp[n][k-1] - dp[n-1][k-n], surely we have to ensure that k>=n
////////////////
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
///////////////////////////////////////////////////////////////////////////////////////////////
const int mod = 1e9 + 7, N = 1010;
class Solution {
    int f[N][N] = {};
public:
    int kInversePairs(int n, int K) {
        // initialize: taking first i number, consisting of 0 inverse pair, only 1 way
        for (int i=0 ; i <= n ; i++) f[i][0] = 1;
        
        long long cur = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                cur = (f[i][j-1] + f[i-1][j] - (j>=i?f[i-1][j-i]:0)) % mod;
                f[i][j] = cur<0?cur+mod:cur;
            }
        }
        return f[n][K];
    }
};