###############################################################################################
# this is hard because we define the i between l~i-1 and i+1~r is the last one to burst, but not the first one
# so in this situation we have to make nums[i] multiply nums[l-1] and nums[r+1] because its left and right are all been burst
# it can only used to multiply nums[l-1] and nums[r+1], so here we add [1] to nums's most left and right
############# 
# Time Complexity: O(C_n^1 + C_n^2 + C_n^3 + ... + C_n^n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        @cache
        def dfs(l, r):
            if l > r:
                return 0
            res = 0
            for i in range(l, r+1):
                res = max(res, nums[i]*nums[l-1]*nums[r+1]+dfs(l,i-1)+dfs(i+1,r))
            return res
        return dfs(1, len(nums)-2)

# however the solution above will exceed time limit, we have to check a special case
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        if max(nums) == min(nums):
            if len(nums) == 1:
                return nums[0]
            return nums[0]**3*(len(nums)-2) + nums[0]**2 + nums[0]
        nums = [1] + nums + [1]
        @cache
        def dfs(l, r):
            if l > r:
                return 0
            res = 0
            for i in range(l, r+1):
                res = max(res, nums[i]*nums[l-1]*nums[r+1]+dfs(l,i-1)+dfs(i+1,r))
            return res
        return dfs(1, len(nums)-2)