###############################################################################################
# dfs exceeds time limit
###########
# 时间复杂度：O(2^45)
# 空间复杂度：O(45)
###############################################################################################
class Solution:
    def climbStairs(self, n: int) -> int:
        def dfs(l):
            if l == n:
                return 1
            ret = 0
            if l + 1 <= n:
                ret += dfs(l+1)
            if l + 2 <= n:
                ret += dfs(l+2)
            return ret
        return dfs(0)

# 改成动规形式
class Solution:
    def climbStairs(self, n: int) -> int:
        one, two, cur = 1, 2, 0
        for _ in range(3, n+1):
            cur = one + two
            one = two
            two = cur
        return cur if n > 2 else n