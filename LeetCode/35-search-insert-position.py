###############################################################################################
# easy
###########
# Time Complexity: O(logn)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            m = (l+r)>>1
            if nums[m] >= target:
                r = m
            else:
                l = m+1
        return l if nums[l] >= target else l+1