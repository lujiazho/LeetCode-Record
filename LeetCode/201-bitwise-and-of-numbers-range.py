###############################################################################################
# time limit exceeded
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        res = left
        for n in range(left+1, right+1):
            res &= n
        return res


# 精妙，直到找到相等的左边，此时右边与一定全为0；边界是都不相等，那最终还是0
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        i = 0
        while left!=right:
            left >>= 1
            right >>= 1
            i += 1
        return left << i