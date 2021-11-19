###############################################################################################
# lowbit
###########
# Time Complexity: O(n), n represents the number of 1's in x^y
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        ham = x ^ y
        res = 0
        while ham:
            res += 1
            ham -= ham & -ham
        return res