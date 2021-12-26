###############################################################################################
# easy hash and sort
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dic = defaultdict(list)
        for x, y in points:
            dic[x*x+y*y].append([x,y])
        res = []
        for key in sorted(dic.keys()):
            res.extend(dic[key])
            if len(res) >= k:
                break
        return res