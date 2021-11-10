###############################################################################################
# dp, this question is easier than version 3 of sell stock
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [-prices[0], 0] # 第i天结束时, 持有和不持有的最大利润, 这里初始化第一天
        for i in range(1, len(prices)):
            newdp = [0, 0]
            newdp[0] = max(dp[0], dp[1] - prices[i]) # 昨天就持有, 今天才买
            newdp[1] = max(dp[1], dp[0] + prices[i]) # 昨天就不持有, 昨天持有但今天卖了
            dp = newdp
        return max(dp)