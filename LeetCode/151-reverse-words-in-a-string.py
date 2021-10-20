###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(c), c is the length of the longest word
###############################################################################################
class Solution:
    def reverseWords(self, s: str) -> str:
        c = ""
        res = ""
        for ch in s[::-1]:
            if ch != " ":
                c += ch
            else:
                if c != "":
                    res += (" " if res != "" else "") + c[::-1]
                c = ""
        if c != "":
            res += (" " if res != "" else "") + c[::-1]
        return res