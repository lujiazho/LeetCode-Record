###############################################################################################
# 还是得用动规的状态转移思想来解，不然一次遍历很难做
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 分别: 第i天结束后，状态为完成第一买，完成第一卖，完成第二买，完成第二卖, 时的利润(不一定是在第i天完成的)
        dp = [-prices[0], 0, -prices[0], 0]
        for i in range(1, len(prices)):
            newdp = []
            newdp.append(max(-prices[i], dp[0])) # 要么今天买的，要么之前买的
            newdp.append(max(prices[i]+dp[0], dp[1])) # 要么今天卖，要么之前卖
            newdp.append(max(dp[1]-prices[i], dp[2])) # 同上
            newdp.append(max(prices[i]+dp[2], dp[3]))
            dp = newdp
        return max(dp)