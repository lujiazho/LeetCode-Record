###############################################################################################
# this problem is a little tricky
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        p0, p2 = 0, len(nums)-1
        for i in range(len(nums)):
            while p2 > i and nums[i] == 2:
                nums[p2], nums[i] = nums[i], nums[p2]
                p2 -= 1
            if nums[i] == 0:
                nums[i], nums[p0] = nums[p0], nums[i]
                p0 += 1