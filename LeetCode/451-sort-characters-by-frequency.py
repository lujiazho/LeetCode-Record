###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def frequencySort(self, s: str) -> str:
        dic = defaultdict(int)
        for ch in s:
            dic[ch] += 1
        lis = []
        for key in dic:
            lis.append((key, dic[key]))
        lis.sort(key=lambda x: -x[1])
        return "".join([per[0]*per[1] for per in lis])