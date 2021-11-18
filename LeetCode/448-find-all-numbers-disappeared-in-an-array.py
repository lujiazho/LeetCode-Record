###############################################################################################
# This problem has a lot of solutions, such as sort. But below is my favorite one.
###########
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for num in nums:
            nums[abs(num)-1] = -abs(nums[abs(num)-1]) # if num exist, nums[num-1] < 0
        res = []
        for i in range(len(nums)):
            if nums[i] > 0: # > 0 means num(i+1) doesn't exist
                res.append(i+1)
        return res