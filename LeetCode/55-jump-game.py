###############################################################################################
# easy, only store how far we can get
###########
# 时间复杂度：O(n), length of nums
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        far, i, n = nums[0], 0, len(nums)
        while i < n-1 and i < far:
            if far >= n-1:
                return True
            i += 1
            far = max(far, i+nums[i])
        return True if far >= n-1 else False