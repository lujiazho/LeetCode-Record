###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n), worst is n, usually not much worse
###############################################################################################
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        f = defaultdict(int)
        for num in nums:
            f[num] += 1
        return [per for per in f if f[per] > 1]

# 精妙，把自己当作哈希表
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            if nums[abs(num)-1] > 0: # 查哈希前要先取abs，不然这个值可能已经变成负数了，取反才是本来的值
                nums[abs(num)-1] *= -1
            else:
                res.append(abs(num)) # 添加时也要注意取正值，因为num本身可能已经成为其他值存在的标志了（即为负
        return res