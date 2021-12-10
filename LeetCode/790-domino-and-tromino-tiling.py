###############################################################################################
# hard, hard to understand
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def numTilings(self, n: int) -> int:
        dp = [[0,0] for _ in range(n+1)]
        mod = int(1e9+7)
        dp[0], dp[1] = [1, 1], [2, 2]
        for i in range(2, n):
            dp[i][0] = dp[i-1][0] + dp[i-2][0] + dp[i-2][1]*2
            dp[i][1] = dp[i-1][0] + dp[i-1][1]
        return dp[n-1][0] % mod