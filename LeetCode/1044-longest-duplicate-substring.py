###############################################################################################
# binary search + hash
###########
# 时间复杂度：O(nlogn)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        ret = ""
        def check(l):
            nonlocal ret
            c = set()
            for i in range(len(s)-l+1):
                if s[i:i+l] in c:
                    ret = s[i:i+l]
                    return True
                c.add(s[i:i+l])
            return False
        llen, rlen = 0, len(s)-1
        while llen < rlen:
            mlen = (llen+rlen+1)>>1
            if check(mlen):
                llen = mlen
            else:
                rlen = mlen - 1
        return ret