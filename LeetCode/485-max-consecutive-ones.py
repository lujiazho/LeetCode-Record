###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        res = cur = 0
        for num in nums:
            if num:
                cur += 1
            else:
                res = max(res, cur)
                cur = 0
        return max(res, cur)