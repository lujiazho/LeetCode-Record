###############################################################################################
# easy
############# 
# Time Complexity: O(bits number of n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if not n:
            return 1
        pre = 1
        res = 0
        while n:
            if not n % 2:
                res += pre
            pre *= 2
            n >>= 1
        return res