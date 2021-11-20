###############################################################################################
# binary search's variant
###########
# Time Complexity: O(logn)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            mid = (l+r)>>1
            if nums[mid-1] < nums[mid] < nums[mid+1]:
                return nums[mid]
            if nums[mid] > nums[mid-1]: # for everytime the mid point to the latter one
                mid += 1
            if mid % 2: # means this is at single element's left
                l = mid + 1
            else:
                r = mid - 2
        return nums[l]