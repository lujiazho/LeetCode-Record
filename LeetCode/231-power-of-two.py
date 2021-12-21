###############################################################################################
# easy, this way is so fast
############# 
# Time Complexity: O(1)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n and not (n - (n&-n)):
            return True
        return False