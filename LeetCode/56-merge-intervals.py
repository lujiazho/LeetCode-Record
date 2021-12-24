###############################################################################################
# easy
############# 
# Time Complexity: O(nlogn)
# Space Complexity: O(logn), used for sort
###############################################################################################
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x: (x[0], x[1]))
        res = []
        start, end = intervals[0][0], intervals[0][1]
        for s, e in intervals[1::]:
            if s <= end:
                end = max(end, e)
            else:
                res.append([start, end])
                start, end = s, e
        res.append([start, end])
        return res