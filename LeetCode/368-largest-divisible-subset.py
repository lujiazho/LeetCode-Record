###############################################################################################
# kind of difficult, steps are below:
# (1) sort array
# (2) define dp
# (3) calculate dp
# (4) backward induction
###########
# Time Complexity: O(n^2)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        # 所有都初始化为1，因为最开始肯定是有自身这个数的
        dp = [1]*len(nums) # dp[i]: 在nums升序下，以nums[i]为最大整数的整除子集大小
        
        max_size, max_idx = 1, 0
        for i in range(1, len(nums)):
            for j in range(i):
                if not nums[i] % nums[j]: # 说明nums[i]能够在nums[j]所代表的子集上扩充
                    dp[i] = max(dp[i], dp[j]+1)
        
            if dp[i] > max_size:
                max_size = dp[i]
                max_idx = i
        
        if max_size == 1:
            return [nums[0]]
        
        res = []
        for i in range(max_idx, -1, -1):
            if dp[i] == max_size and not nums[max_idx] % nums[i]:
                res.append(nums[i])
                max_idx = i
                max_size -= 1
                if not max_size:
                    break
        return res