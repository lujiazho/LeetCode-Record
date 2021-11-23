###############################################################################################
# disjoint set union
###########
# Time Complexity: O(n*sqrt(m)), n is length of nums, m is maximum of all nums
# Space Complexity: O(m)
###############################################################################################
class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        father = list(range(max(nums)+1))
        
        def find(x):
            if father[x] != x:
                father[x] = find(father[x])
            return father[x]
        
        for num in nums:
            for c in range(2, int(math.sqrt(num))+1):
                if not num % c:
                    father[find(c)] = find(num)
                    father[find(num//c)] = find(num)
        d = defaultdict(int)
        for num in nums:
            d[find(num)] += 1
        return max(d.values())