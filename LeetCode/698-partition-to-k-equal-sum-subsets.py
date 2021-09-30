###############################################################################################
# dfs violence search lead to time limit exceeded，这个思路是把每个数往不同集合中放
###########
# 时间复杂度：O(4^16)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if sum(nums) % k or k > n:
            return False
        dic, target = [0]*k, sum(nums) // k
        def dfs(cur):
            if cur == n:
                for per in dic:
                    if per != target:
                        return False
                return True
            for i in range(k):
                if nums[cur] + dic[i] <= target:
                    dic[i] += nums[cur]
                    if dfs(cur+1):
                        return True
                    dic[i] -= nums[cur]
                    if not dic[i]: # 这里加了个剪枝，还是超时
                        break
            return False
        return dfs(0)

# 因为上面有很多小的数，都堆在一个集合了，导致很多无效搜索；因此从大的开始，就大大减少时间消耗了，当然得先排个序
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if sum(nums) % k or k > n:
            return False
        dic, target = [0]*k, sum(nums) // k
        nums.sort()
        def dfs(cur):
            if cur == -1:
                for per in dic:
                    if per != target:
                        return False
                return True
            for i in range(k):
                if nums[cur] + dic[i] <= target:
                    dic[i] += nums[cur]
                    if dfs(cur-1):
                        return True
                    dic[i] -= nums[cur]
                    if not dic[i]:
                        break
            return False
        return dfs(n-1)