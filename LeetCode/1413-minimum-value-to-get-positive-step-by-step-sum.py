###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        min_ = s = nums[0]
        for i in range(1, len(nums)):
            s += nums[i]
            if s < min_:
                min_ = s
        return 1-min_ if min_ < 0 else 1