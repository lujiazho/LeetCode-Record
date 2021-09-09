###############################################################################################
# dp + n^3的算法，无语了；我这个dp是相当于处理order
###########
# 时间复杂度：O(n^3)
# 空间复杂度：O(n^3)
###############################################################################################
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        mines = set([(x,y) for x,y in mines])
        maxOrder, res = ceil(n/2), 0
        dp = [[[0]*(maxOrder+1) for _ in range(n)] for _ in range(n)] # dp[i][j][k]: (i,j)位置处，order为k是否可行
        for order in range(1, maxOrder+1):
            arm = order - 1
            for i in range(arm, n - arm):
                for j in range(arm, n - arm):
                    if order == 1:
                        if (i,j) not in mines:
                            dp[i][j][order] = 1
                    else:
                        if dp[i][j][order-1] and dp[i][j-arm][1] and dp[i+arm][j][1] and dp[i][j+arm][1] and dp[i-arm][j][1]:
                            dp[i][j][order] = dp[i][j][order-1] + 1
                    res = max(res, dp[i][j][order])
        return res

# 减少dp一个维度，但无济于事，还是超时
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        mines = set([(x,y) for x,y in mines])
        maxOrder, res = ceil(n/2), 0
        dp = [[0 for _ in range(n)] for _ in range(n)] # dp[i][j]: (i,j)位置处，order为k是否可行
        for i in range(n):
            for j in range(n):
                if (i,j) not in mines:
                    dp[i][j] = 1
                    res = 1
        dp_1 = deepcopy(dp)
        for order in range(2, maxOrder+1):
            arm = order - 1
            for i in range(arm, n - arm):
                for j in range(arm, n - arm):
                    if not (dp[i][j] and dp_1[i][j-arm] and dp_1[i+arm][j] and dp_1[i][j+arm] and dp_1[i-arm][j]):
                        dp[i][j] = 0 # 要置为0
                    else:
                        res = max(res, order)
        return res

###############################################################################################
# 官方的dp，预处理每个(i,j)位置的最大上右下左臂长，这个只需要n^2，预处理完后，再遍历一遍即可
###########
# 时间复杂度：O(n^2)
# 空间复杂度：O(n^2)
###############################################################################################
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        mines = set([(x,y) for x,y in mines])
        dp = [[n for _ in range(n)] for _ in range(n)] # dp[i][j]表示(i,j)处四个方向上最小的臂长，也就能计算出此处的最大order
        for i in range(n):
            l = 0 # 左臂
            for j in range(n):
                l = l + 1 if (i,j) not in mines else 0
                if l < dp[i][j]: # 第i横排
                    dp[i][j] = l
            
            r = 0 # 右臂
            for j in range(n-1, -1, -1):
                r = r + 1 if (i,j) not in mines else 0
                if r < dp[i][j]:
                    dp[i][j] = r
                    
        for i in range(n):
            u = 0 # 上臂
            for j in range(n):
                u = u + 1 if (j,i) not in mines else 0
                if u < dp[j][i]: # 第i竖排
                    dp[j][i] = u
            
            d = 0 # 下臂
            for j in range(n-1, -1, -1):
                d = d + 1 if (j,i) not in mines else 0
                if d < dp[j][i]:
                    dp[j][i] = d
        
        res = 0
        for i in range(n):
            for j in range(n):
                res = max(res, dp[i][j])
        return res

# 受到英文版leetcode一位大神的启发，还能进一步合并...太强了
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        mines = set([(x,y) for x,y in mines])
        dp = [[n for _ in range(n)] for _ in range(n)] # dp[i][j]表示(i,j)处四个方向上最小的臂长，也就能计算出此处的最大order
        for i in range(n):
            l = r  = u = d = 0 # 左臂,右臂,上臂,下臂
            for j, k in zip(range(n), range(n-1, -1, -1)):
                l = l + 1 if (i,j) not in mines else 0
                r = r + 1 if (i,k) not in mines else 0
                u = u + 1 if (j,i) not in mines else 0
                d = d + 1 if (k,i) not in mines else 0
                if l < dp[i][j]: # 从左往右
                    dp[i][j] = l
                if r < dp[i][k]: # 从右往左
                    dp[i][k] = r
                if u < dp[j][i]: # 从上往下
                    dp[j][i] = u
                if d < dp[k][i]: # 从下往上
                    dp[k][i] = d

        res = 0
        for i in range(n):
            for j in range(n):
                res = max(res, dp[i][j])
        return res