###############################################################################################
# 两次循环解决
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)，返回值不考虑
###############################################################################################
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        for i in range(len(shifts)-2, -1, -1):
            shifts[i] += shifts[i+1]
        def shift(x, times):
            id_ = ord(x) + times%26
            if id_ > 122:
                return chr(id_ - 26)
            return chr(id_)
        res = []
        for i in range(len(s)):
            res.append(shift(s[i], shifts[i]))
        return ''.join(res)