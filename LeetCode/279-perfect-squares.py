###############################################################################################
# this tree is binary search tree, so we can use binary search to divide it
###########
# 时间复杂度：O(Π(n//i), i∈(1, sqrt(n)+1))，累乘符号Π
# 空间复杂度：O(sqrt(n))
###############################################################################################
class Solution:
    def numSquares(self, n: int) -> int:
        def dfs(i, n, res):
            if not i:
                return res if not n else float("inf")
            ret = float("inf")
            ret = min(ret, dfs(i-1, n, res))
            while i*i <= n:
                res += 1
                n -= i*i
                ret = min(ret, dfs(i-1, n, res))
            return ret
        return dfs(100, n, 0)

# 改成迭代还是超时
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [defaultdict(int) for _ in range(101)] # val:res
        for i in range(n+1):
            dp[1][n-i] = i
        ret = n
        for i in range(2, 101):
            for val in dp[i-1]:
                res, x = dp[i-1][val], val
                dp[i][val] = min(res, dp[i][val]) if dp[i][x] else res # 一个都不用
                while i*i <= x:
                    res += 1
                    x -= i*i
                    dp[i][x] = min(res, dp[i][x]) if dp[i][x] else res # 循环加入能用的可能
                if 0 in dp[i]:
                    ret = min(ret, dp[i][0]) # 如果这一轮有0出现，则和全局比较
        return ret

# 改成以前写的动规了，虽然超时，但当时的思路却更清晰，退步了啊
class Solution:
    def numSquares(self, n: int) -> int:
        sq = int(sqrt(n))
        dp = [[float("inf")]*(n+1) for _ in range(sq+1)] # 用前i个，凑成j的最小使用个数
        for i in range(1, sq+1):
            dp[i][1] = 1 # 只能用一个1
            dp[i][0] = 0 # 一个都不用
        for i in range(n+1):
            dp[1][i] = i
        for i in range(2, sq+1):
            square = i*i
            for j in range(2, n+1):
                dp[i][j] = min([dp[i-1][j-square*k]+k for k in range(j//square+1)])
        return dp[sq][n]

# 化了下简，去掉了第三个循环，还是超时？？？？？
class Solution:
    def numSquares(self, n: int) -> int:
        sq = int(sqrt(n))
        dp = [[float("inf")]*(n+1) for _ in range(sq+1)] # 用前i个，凑成j的最小使用个数
        for i in range(1, sq+1):
            dp[i][1] = 1 # 只能用一个1
            dp[i][0] = 0 # 一个都不用
        for i in range(n+1):
            dp[1][i] = i
        for i in range(2, sq+1):
            square = i*i
            for j in range(2, n+1):
                if square <= j:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-square]+1)
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[sq][n]

# 继续化，过了
class Solution:
    def numSquares(self, n: int) -> int:
        dp = list(range(n+1)) # 用前i个，凑成j的最小使用个数
        for i in range(2, int(sqrt(n))+1):
            square = i*i
            for j in range(square, n+1):
                dp[j] = min(dp[j], dp[j-square]+1)
        return dp[n]

# 本想再化一下之前写的迭代暴搜那个，但思路不清晰导致数据结构定义混乱，难改