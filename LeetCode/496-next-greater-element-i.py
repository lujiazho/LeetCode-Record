###############################################################################################
# easy
###########
# 时间复杂度：O(n^2)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n2 = defaultdict(int)
        for i, num in enumerate(nums2):
            n2[num] = i
        res = [-1]*len(nums1)
        for ind, num in enumerate(nums1):
            i = n2[num]
            for j in range(i, len(nums2)):
                if nums2[j] > num:
                    res[ind] = nums2[j]
                    break
        return res