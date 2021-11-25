###############################################################################################
# easy
###########
# Time Complexity: O(n), n is length of nums
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = res = nums[0]
        for i in range(1, len(nums)):
            if s < 0:
                s = 0
            s += nums[i]
            res = max(res, s)
        return res

###############################################################################################
# segment tree is a typical application of 'divide and conquer'
###########
# Time Complexity: O((1+2+4+...+2^(logn-1))), the asymptotic TC is n
# Space Complexity: O(logn), stack space consumption
###############################################################################################
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # return: 0 lsum, 1 rsum, 2 msum, 3 isum
        def divide_conquer(l, r):
            if l == r:
                return nums[l], nums[l], nums[l], nums[l]
            mid = (l+r)>>1
            l_lsum, l_rsum, l_msum, l_isum = divide_conquer(l, mid)
            r_lsum, r_rsum, r_msum, r_isum = divide_conquer(mid+1, r)
            return max(l_lsum, l_isum+r_lsum), max(r_rsum, r_isum+l_rsum), max(l_msum, r_msum, l_rsum+r_lsum), l_isum+r_isum
        return divide_conquer(0, len(nums)-1)[2]