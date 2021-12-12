###############################################################################################
# this is different from normal DP, not easy
############# 
# Time Complexity: O(n^2)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2:
            return False
        dp = [True] + [False]*(s>>1)
        for num in nums:
            for j in range(s>>1, num-1, -1): # from right to left
                dp[j] |= dp[j-num]
        return dp[s>>1]

# if from left to right, there will be problem, for example: the nums = [2, 8]
# the num = 2, j starts from 2, so dp[2] |= dp[2-2] = dp[0] = True
# then when j goes to 4, dp[4] |= dp[4-2] = dp[2] = True, however the 4 is unachievable
# likewise, dp[6] |= dp[6-2] = dp[4] = True, this is the problem, 2 will be used more than 1 time


###############################################################################################
# dfs
############# 
# Time Complexity: O(2^n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        def dfs(num, i): # the dfs means whether we can get sum of num from nums, or achievable
            if not num:
                return True
            if i >= len(nums) or num < 0:
                return False
            # chose ith or not
            return dfs(num-nums[i], i+1) or dfs(num, i+1)
        return dfs(sum(nums)>>1, 0)


# memorization, which means make it to DP, it can be easily done with @cache
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        @cache
        def dfs(num, i):
            if not num:
                return True
            if i >= len(nums) or num < 0:
                return False
            # chose ith or not
            return dfs(num-nums[i], i+1) or dfs(num, i+1)
        return dfs(sum(nums)>>1, 0)

# or manually
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        dp = [[-1]*((sum(nums)>>1)+1) for _ in range(len(nums))]
        def dfs(num, i):
            if not num:
                return True
            if i >= len(nums) or num < 0:
                return False
            if dp[i][num] != -1:
                return dp[i][num]
            # chose ith or not
            dp[i][num] = dfs(num-nums[i], i+1) or dfs(num, i+1)
            return dp[i][num]
        return dfs(sum(nums)>>1, 0)
# from the dfs, we can see why we have to start from right to left in previous DP method. Because we climb from bottom to top in dfs