###############################################################################################
# 暴搜超时
###########
# 时间复杂度：O(2^5000)
# 空间复杂度：O(log5000)
###############################################################################################
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        def dfs(i, status, earn, buyday, selday): # buyday: 上次买入的天数
            if i == n:
                return earn
            ret = earn
            if status: # 现在手上有股票
                ret = max(dfs(i+1, 1, earn, buyday, selday), ret) # 不卖
                if prices[i] > prices[buyday]:
                    ret = max(dfs(i+1, 0, earn+prices[i]-prices[buyday], buyday, i), ret) # 卖
            else:
                if i - selday > 1:
                    ret = max(dfs(i+1, 1, earn, i, selday), ret) # 买
                ret = max(dfs(i+1, 0, earn, buyday, selday), ret) # 不买
            return ret
        return dfs(0, 0, 0, 0, -2)

# 剔除重复，仍然超时
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        walked = defaultdict(int)
        def dfs(i, status, earn, buyday, selday): # buyday: 上次买入的天数
            if i == n:
                return earn
            now = (i, status, buyday) if status else (i, status, i - selday > 1)
            if now in walked and walked[now] >= earn:
                return earn
            walked[now] = earn
            ret = earn
            if status: # 现在手上有股票
                ret = max(dfs(i+1, 1, earn, buyday, selday), ret) # 不卖
                if prices[i] > prices[buyday]:
                    ret = max(dfs(i+1, 0, earn+prices[i]-prices[buyday], buyday, i), ret) # 卖
            else:
                if i - selday > 1:
                    ret = max(dfs(i+1, 1, earn, i, selday), ret) # 买
                ret = max(dfs(i+1, 0, earn, buyday, selday), ret) # 不买
            return ret
        return dfs(0, 0, 0, 0, -2)

# 动规，对状态转移还是不够敏感
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0]*3 for _ in range(n)] # 【dp[i]: 第i天结束后, [0]有股票, [1]无股票且可买, [2]冷冻期】: 的收益
        dp[0][0], dp[0][1], dp[0][2] = [-prices[0], 0, 0]
        for i in range(1, n):
            # 昨天结束后就持有；今天买的(所以昨天结束后不能是冷冻期)
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
            # 昨天结束后就没有股票；昨天结束后冷冻期
            dp[i][1] = max(dp[i-1][1], dp[i-1][2])
            # 昨天结束后有股票，今天卖，因此今天结束后进入冷冻期
            dp[i][2] = dp[i-1][0] + prices[i]
        return max(dp[n-1][i] for i in range(3))

# 化个简
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [-prices[0], 0, 0]
        for i in range(1, len(prices)):
            newdp = [max(dp[0], dp[1] - prices[i]), max(dp[1], dp[2]), dp[0] + prices[i]]
            dp = newdp
        return max(dp)