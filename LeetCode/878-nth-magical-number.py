###############################################################################################
# math is so important in this question
# 1 use math to calculate lcm by gcd
# 2 use math to check how many numbers can be divisible by a or b before a certain number in O(1)
############# 
# Time Complexity: O(logn)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        lcm, mod = a*b//gcd(a,b), int(1e9+7)
        l, r = min(a, b), min(a, b)*n
        while l < r:
            mid = (l+r)>>1
            if mid//a + mid//b - mid//lcm < n:
                l = mid + 1
            else:
                r = mid
        return l % mod