###############################################################################################
# easy
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def maxPower(self, s: str) -> int:
        length = res = 1
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                length += 1
                res = max(length, res)
            else:
                length = 1
        return res