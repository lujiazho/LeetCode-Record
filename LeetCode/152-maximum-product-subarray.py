###############################################################################################
# kind of tricky, we need to record the previous max and min, max is used to calculate res value
# min is used to calculate the next possible max value
# and because we don't know the sign pf nums[i], so we need to use both curMin and curMax to calculate current max and min
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = curMax = curMin = nums[0] # previous max and min product
        for i in range(1, len(nums)):
            pres = (nums[i], curMin*nums[i], curMax*nums[i])
            curMax, curMin = max(pres), min(pres)
            res = max(res, curMax)
        return res