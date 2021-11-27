###############################################################################################
# interesting, use prefix & suffix product
###########
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre, suf = [nums[0]], [nums[-1]]
        for i in range(1, len(nums)):
            pre.append(pre[-1]*nums[i])
            suf.append(suf[-1]*nums[len(nums)-i-1])
        return [(pre[i-1] if i-1>=0 else 1)*(suf[len(nums)-2-i] if len(nums)-2-i >= 0 else 1) for i in range(len(nums))]


# reduce the space complexity to O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res, pre, suf = [1]*len(nums), 1, 1
        for i in range(1, len(nums)):
            pre *= nums[i-1]
            res[i] *= pre
        for i in range(len(nums)-2, -1, -1):
            suf *= nums[i+1]
            res[i] *= suf
        return res

# reduce the loop to one pass
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res, pre, suf = [1]*len(nums), 1, 1
        for i in range(1, len(nums)):
            pre *= nums[i-1]
            res[i] *= pre
            suf *= nums[len(nums)-i]
            res[len(nums)-i-1] *= suf
        return res