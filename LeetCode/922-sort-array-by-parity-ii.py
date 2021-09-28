###############################################################################################
# easy, two pointers
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        eve, odd, len_ = 0, 1, len(nums)
        while odd < len_ and eve < len_:
            while odd < len_ and nums[odd] % 2:
                odd += 2
            while eve < len_ and not nums[eve] % 2:
                eve += 2
            if odd < len_ and eve < len_:
                nums[odd], nums[eve] = nums[eve], nums[odd]
        return nums