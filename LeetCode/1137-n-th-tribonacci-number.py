###############################################################################################
# 简单
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return n if n != 2 else 1
        f0, f1, f2 = 0, 1, 1
        for _ in range(3, n+1):
            f3 = f0 + f1 + f2
            f2, f1, f0 = f3, f2, f1
        return f3

# 递归写法
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return n if n != 2 else 1
        def dfs(f0, f1, f2, l):
            if l > n:
                return f2
            return dfs(f1, f2, f0+f1+f2, l+1)
        return dfs(0, 1, 1, 3)