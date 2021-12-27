###############################################################################################
# easy
############# 
# Time Complexity: O(number of bits)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def findComplement(self, num: int) -> int:
        res = 0
        acc = 0
        while num:
            if not num%2:
                res += (1<<acc)
            num >>= 1
            acc += 1
        return res