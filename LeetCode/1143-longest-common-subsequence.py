###############################################################################################
# Kind of easy
###########
# 时间复杂度：O(m*n), m is len of text1, n is len of text2
# 空间复杂度：O(m*n)
###############################################################################################
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp[i][j]: text1前i个 text2前j个(i,j==0表示没有)的len of longest common subsequence
        dp = [[0]*(len(text2)+1) for _ in range(len(text1)+1)]
        for i in range(1, len(text1)+1):
            for j in range(1, len(text2)+1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        return dp[len(text1)][len(text2)]

# deminish memory usage
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp[i][j]: text1前i个 text2前j个(i,j==0表示没有)的len of longest common subsequence
        dp = [0]*(len(text2)+1)
        for i in range(1, len(text1)+1):
            newdp = [0]*(len(text2)+1)
            for j in range(1, len(text2)+1):
                if text1[i-1] == text2[j-1]:
                    newdp[j] = dp[j-1] + 1
                else:
                    newdp[j] = max(dp[j], newdp[j-1], dp[j-1])
            dp = newdp # don't have to use deepcopy, which can be time-consuming
        return dp[len(text2)]