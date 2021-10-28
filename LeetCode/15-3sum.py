###############################################################################################
# 看起来像三个循环，其实第三个循环在整个函数运行过程中不会运行超过O(n)次
###########
# 时间复杂度：O(n^2)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        dic = defaultdict(list)
        for i, num in enumerate(nums):
            if len(dic[num]) < 3: # 剪枝
                dic[num].append(i)
        
        res = set()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if dic[-(nums[i] + nums[j])]:
                    for k in dic[-(nums[i] + nums[j])]:
                        if k > j:
                            x = sorted([nums[i], nums[j], nums[k]])
                            res.add(tuple(x))
                            break
        return [list(per) for per in res]