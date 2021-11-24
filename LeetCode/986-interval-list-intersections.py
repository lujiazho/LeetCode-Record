###############################################################################################
# easy
###########
# Time Complexity: O(m + n), m is length of first list, n is length of second list
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = j = 0
        res = []
        while i < len(firstList) and j < len(secondList):
            l = max(firstList[i][0], secondList[j][0])
            r = min(firstList[i][1], secondList[j][1])
            if l <= r:
                res.append([l,r])
            if firstList[i][1] > secondList[j][1]:
                j += 1
            else:
                i += 1
        return res