###############################################################################################
# 这道题的动规比较难想，典型计数DP
###########
# 时间复杂度：O(mn), m和n分别s和t的长度
# 空间复杂度：O(mn)
###############################################################################################
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [[0]*(len(t)+1) for _ in range(len(s)+1)] # dp[i][j]: s[i:]的子序列中t[j:]出现的数量
        for i in range(len(t)):
            dp[len(s)][i] = 0 # s[len(s):]是空串，不可能出现t的非空子串
        for i in range(len(s)+1):
            dp[i][len(t)] = 1 # t[len(t):]是空串，是任何s子串的子序列
        for i in range(len(s)-1, -1, -1):
            for j in range(len(t)-1, -1, -1):
                dp[i][j] = dp[i+1][j] # 不用i和j匹配，从s[i+1:]开始
                if s[i] == t[j]: # 当相等的时候，则可以匹配，因此加上s[i+1:]和t[j+1:]的匹配数量
                    dp[i][j] += dp[i+1][j+1]
        return dp[0][0]

# 上面是定义的s[i:]和t[j:]，即后面那一块，定义前面那一块也可以
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [[0]*(len(t)+1) for _ in range(len(s)+1)] # dp[i][j]: s[:i]的子序列中t[:j]出现的数量
        for i in range(1, len(t)+1):
            dp[0][i] = 0 # s[:0]是空串，不可能出现t的非空子串
        for i in range(len(s)+1):
            dp[i][0] = 1 # t[:0]是空串，是任何s子串的子序列
        for i in range(1, len(s)+1):
            for j in range(1, len(t)+1):
                dp[i][j] = dp[i-1][j] # 不用i和j匹配，从s[i+1:]开始
                if s[i-1] == t[j-1]: # 当相等的时候，则可以匹配，因此加上s[i+1:]和t[j+1:]的匹配数量
                    dp[i][j] += dp[i-1][j-1]
        return dp[-1][-1]