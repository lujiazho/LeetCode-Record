###############################################################################################
# not hard
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        dic = defaultdict(int)
        for t in time:
            dic[t%60] += 1
        res = 0
        for t in time:
            if t % 60:
                another = 60 - t%60
                if another in dic and (another != t%60 or dic[another] > 1):
                    res += dic[another] if another != t%60 else dic[another] - 1
            else:
                res += dic[0] - 1
        return res // 2

# this is better
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        dic = defaultdict(int)
        res = 0
        for t in time:
            another = 60 - t%60 if t % 60 else 0
            if another in dic:
                res += dic[another]
            dic[t%60] += 1
        return res