###############################################################################################
# 用哈希表存储出现次数，把共同的元素的最小出现次数取出来
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1, set2 = defaultdict(int), defaultdict(int)
        for n1 in nums1:
            set1[n1] += 1
        for n2 in nums2:
            set2[n2] += 1
        intersection = set1.keys() & set2.keys()
        res = []
        for per in intersection:
            res.extend([per]*min(set1[per], set2[per]))
        return res