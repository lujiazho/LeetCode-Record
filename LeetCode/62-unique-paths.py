###############################################################################################
# easy
###########
# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
###############################################################################################
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1]*n for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[m-1][n-1]

## reduce dimension
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1]*n
        for i in range(1, m):
            ndp = [1]*n
            for j in range(1, n):
                ndp[j] = ndp[j-1] + dp[j]
            dp = ndp
        return dp[n-1]